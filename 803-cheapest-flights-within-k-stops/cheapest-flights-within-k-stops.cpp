class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: adjList ko adjacency list ke form me build karte hain
        unordered_map<int, list<pair<int, int>>> adjList;
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2]; // (UVW Representation)
            adjList[u].push_back({v, w}); // u se v tak ka path with cost w
        }

        // Step 2: Priority Queue (Min-Heap) jo cheapest cost wale nodes ko pehle pick karega
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0}); // {cost, src, stops} -> Pehle cost 0, source se shuru karenge, 0 stops

        // Step 3: Har city tak pahunchne ke liye minimum stops track karne ke liye vector
        vector<int> visited(n, INT_MAX);
        visited[src] = 0; // Source tak pahunchne ke liye 0 stops

        // Step 4: BFS traversal (Dijkstra jaisa) jo cheapest cost pe focus karega
        while (!pq.empty()) {
            auto [cost, city, stops] = pq.top(); // Current node ka cost, city aur stops nikalte hain
            pq.pop();

            // Agar destination pahunch gaye to cost return kar do
            if (city == dst)
                return cost;

            // Agar stops allowed limit se zyada ho gaye to ignore kar do
            if (stops > k)
                continue;

            // Agar current city pe pehle hi kam stops me pahunch chuke hain to skip kar do
            if (visited[city] < stops)
                continue;

            // Current city tak ka minimum stops update karte hain
            visited[city] = stops;

            // Ab saare neighbors explore karte hain
            for (auto& [next_city, price] : adjList[city]) {
                pq.push({cost + price, next_city, stops + 1}); // Cost update karke next_city queue me daal do
            }
        }
        
        return -1; // Agar destination tak koi valid path nahi mila to -1 return kar do
    }
};
