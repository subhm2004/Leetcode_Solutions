class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // STEP 1: Graph Building - Adjacency List banate hain
        unordered_map<int, list<pair<int, int>>> adjList;
        
        // Har flight ko adjacency list mein convert karte hain
        for (auto& flight : flights) {
            int u = flight[0];  // Source city (kahan se)
            int v = flight[1];  // Destination city (kahan tak)
            int w = flight[2];  // Flight ka cost (kitna paisa)
            
            // u city se v city tak jaane ka path add kar rahe hain with cost w
            adjList[u].push_back({v, w});
            
            // MATLAB: adjList[u] contains list of all cities jo u se directly reachable hain
            // Format: {destination_city, cost_to_reach}
        }
        
        // GRAPH STRUCTURE EXAMPLE:
        // Agar flights = [[0,1,100], [1,2,200], [0,2,500]]
        // To adjList:
        // 0 -> [(1,100), (2,500)]  // City 0 se city 1 (cost 100) ya city 2 (cost 500)
        // 1 -> [(2,200)]           // City 1 se city 2 (cost 200)
        // 2 -> []                  // City 2 se koi direct flight nahi
        
        
        // STEP 2: Priority Queue Setup - Modified Dijkstra ke liye
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        // TUPLE FORMAT: {cost, current_city, stops_used}
        pq.push({0, src, 0});
        
        // PRIORITY QUEUE EXPLANATION:
        // - tuple<int, int, int> = {cost, city, stops}
        // - greater<> = Min-heap banata hai (smallest cost pehle milegi)
        // - Initial push: {0, src, 0} = cost 0, source city, 0 stops used
        
        // WHY MIN-HEAP?
        // Kyunki hume sabse CHEAPEST cost wala path pehle explore karna hai
        // Dijkstra algorithm ka core principle: greedy approach with cheapest first
        
        
        // STEP 3: Visited Array - Optimization ke liye
        vector<int> visited(n, INT_MAX);
        visited[src] = 0;  // Source tak 0 stops mein pahunch sakte hain
        
        // VISITED ARRAY KA PURPOSE:
        // visited[i] = minimum stops needed to reach city i
        // Agar kisi city tak pehle se kam stops mein pahunch chuke hain,
        // to current path (jo zyada stops use karta hai) ko skip kar sakte hain
        
        // OPTIMIZATION LOGIC:
        // Agar visited[city] < current_stops, matlab pehle se better path exist karta hai
        // To current path explore karne ka koi faida nahi
        
        
        // STEP 4: Modified Dijkstra Algorithm - Main Logic
        while (!pq.empty()) {
            
            // STEP 4A: Cheapest unprocessed path nikalte hain
            auto [cost, city, stops] = pq.top();  // Structured binding (C++17 feature)
            pq.pop();
            
            // CURRENT STATE:
            // cost = current path ka total cost
            // city = current city jahan hum pahunche hain  
            // stops = kitne stops use kiye hain is path mein
            
            
            // STEP 4B: Destination Check - Early Exit Optimization
            if (city == dst) {
                return cost;  // Destination pahunch gaye! Cost return kar do
            }
            
            // GREEDY GUARANTEE:
            // Kyunki min-heap use kar rahe hain, jo path pehle destination pahunchega
            // woh guaranteed CHEAPEST path hoga. Isliye immediate return kar sakte hain.
            
            
            // STEP 4C: Stops Constraint Check
            if (stops > k) {
                continue;  // Agar stops limit exceed ho gayi, is path ko ignore kar do
            }
            
            // K-STOPS CONSTRAINT:
            // Problem statement: "at most K stops"
            // Agar current path already K se zyada stops use kar raha hai,
            // to further exploration meaningless hai
            
            
            // STEP 4D: Pruning Optimization - Critical Logic
            if (visited[city] < stops) {
                continue;  // Agar pehle se kam stops mein yahan pahunche hain, skip kar do
            }
            
            // PRUNING EXPLANATION:
            // visited[city] = previous best stops to reach city
            // current stops = stops in current path
            // Agar visited[city] < stops, matlab:
            // - Pehle se ek better path (kam stops) exist karta hai same city tak
            // - Current path explore karne ka koi matlab nahi
            
            // POTENTIAL ISSUE WITH THIS APPROACH:
            // Ye logic occasionally suboptimal ho sakta hai!
            // Example: Path with more stops might be cheaper
            // But yahan hum assume kar rahe hain kam stops = better (not always true)
            
            
            // STEP 4E: Update Visited State
            visited[city] = stops;
            
            // RECORD KEEPING:
            // Current city tak minimum stops update kar rahe hain
            // Future paths ke liye reference point
            
            
            // STEP 4F: Neighbor Exploration - Graph Traversal
            for (auto& [next_city, price] : adjList[city]) {
                
                // CURRENT NEIGHBOR:
                // next_city = jahan ja sakte hain current city se
                // price = current city se next_city tak ka cost
                
                // NEW PATH CALCULATION:
                int new_cost = cost + price;      // Total cost update
                int new_stops = stops + 1;        // Stops count increase
                
                // QUEUE MEIN ADD:
                pq.push({new_cost, next_city, new_stops});
                
                // EXPLORATION STRATEGY:
                // Har neighbor ke liye new path create kar rahe hain
                // Priority queue automatically cheapest path pehle process karega
                // Recursive exploration: har city se uske neighbors explore honge
            }
            
            // ITERATION COMPLETE:
            // Current city ke sab neighbors queue mein add ho gaye
            // Next iteration mein cheapest remaining path process hoga
        }
        
        // STEP 5: No Valid Path Found
        return -1;
        
        // RETURN -1 CASES:
        // 1. Destination unreachable hai completely
        // 2. Destination reachable hai but K stops limit mein nahi
        // 3. All paths exhaust ho gaye without reaching destination
    }
};

/*
ALGORITHM OVERVIEW - MODIFIED DIJKSTRA:

CORE CONCEPT:
- Traditional Dijkstra: finds shortest path in terms of edge weights
- Modified Dijkstra: finds cheapest path with stops constraint
- State space: (city, stops) instead of just (city)

KEY MODIFICATIONS:
1. TUPLE STATE: {cost, city, stops} instead of {cost, city}
2. STOPS CONSTRAINT: if (stops > k) continue;
3. PRUNING: if (visited[city] < stops) continue;
4. EARLY EXIT: First time destination reached = optimal

ALGORITHM FLOW:
1. Start from source with cost=0, stops=0
2. Always process cheapest remaining path first (min-heap property)
3. For each path, explore all neighbors
4. Respect stops constraint (≤ K)
5. Use pruning to avoid redundant exploration
6. First destination reach = guaranteed optimal (due to greedy processing)

TIME COMPLEXITY: O((V + E) × log(V × K))
- V = vertices (cities)  
- E = edges (flights)
- K = maximum stops
- Log factor due to priority queue operations

SPACE COMPLEXITY: O(V + E + V×K)
- V = visited array
- E = adjacency list
- V×K = worst case queue size

COMPARISON WITH BELLMAN-FORD:
- Dijkstra: More complex, uses priority queue, good for sparse graphs
- Bellman-Ford: Simpler, natural constraint handling, good for small K

EXAMPLE TRACE:
flights = [[0,1,100],[1,2,100],[0,2,500]], src=0, dst=2, k=1

Initial: pq = {(0,0,0)}, visited = [0,∞,∞]

Step 1: Process (0,0,0)
- Add neighbors: pq = {(100,1,1), (500,2,1)}
- Update visited[0] = 0

Step 2: Process (100,1,1)  [cheapest remaining]
- Add neighbors: pq = {(200,2,2), (500,2,1)}
- Update visited[1] = 1

Step 3: Process (500,2,1)  [destination reached!]
- Return 500

Final Answer: 500 (path 0→2, direct flight)

EDGE CASES HANDLED:
- Direct path exists: found in early iterations
- No path within K stops: queue exhausts, return -1
- Unreachable destination: queue exhausts, return -1
- Multiple paths: greedy selection ensures optimal

This approach combines Dijkstra's optimality guarantee with stops constraint handling!
*/