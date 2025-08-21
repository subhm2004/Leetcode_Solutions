class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Method 1: Standard Dijkstra with State (city, stops)
        
        // Graph building
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            graph[u].push_back({v, w});
        }
        
        // Priority Queue: {cost, city, stops}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});
        
        // Distance array: dist[city][stops] = minimum cost
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        
        while (!pq.empty()) {
            auto [cost, city, stops] = pq.top();
            pq.pop();
            
            // Early termination
            if (city == dst) return cost;
            
            // Stop constraint check
            if (stops > k) continue;
            
            // Pruning: agar already better solution mil gaya hai
            if (dist[city][stops] < cost) continue;
            
            // Explore neighbors
            for (auto& [nextCity, price] : graph[city]) {
                int newCost = cost + price;
                int newStops = stops + 1;
                
                if (newStops <= k + 1 && newCost < dist[nextCity][newStops]) {
                    dist[nextCity][newStops] = newCost;
                    pq.push({newCost, nextCity, newStops});
                }
            }
        }
        
        return -1;
    }
    
    // Method 2: Bellman-Ford Approach (Alternative)
    int findCheapestPriceBellmanFord(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        // K+1 iterations (kyunki maximum K stops allowed hai)
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                
                if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            
            dist = temp;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

// Usage example:
/*
Input: 
n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0, dst = 3, k = 1

Expected Output: 700

Explanation:
Path: 0->1->3 with cost 100+600=700 (1 stop)
Alternative: 0->1->2->3 would be 100+100+200=400 but needs 2 stops (not allowed)
*/