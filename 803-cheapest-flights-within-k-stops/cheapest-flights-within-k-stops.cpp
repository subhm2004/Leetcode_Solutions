class Solution {
public:

    
    // Method 2: Bellman-Ford Approach (Alternative)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
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