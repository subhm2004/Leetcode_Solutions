class Solution {
public:    
    void findBridges(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, 
                     unordered_map<int, bool>& visited, vector<vector<int>>& ans, 
                     unordered_map<int, list<int>>& adjList) {
        
        // Node ko visit mark karo
        visited[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;
        
        // Sare neighbors ke liye loop chalao
        for (auto nbr : adjList[src]) {
            // Agar parent node hai toh skip karo
            if (nbr == parent)
                continue;
            
            // Agar neighbor visitedited nahi hai
            if (!visited[nbr]) {
                // DFS call karo
                findBridges(nbr, src, timer, tin, low, visited, ans, adjList);
                
                // Low value ko update karo
                low[src] = min(low[src], low[nbr]);
                
                // Check karo ki bridge hai ya nahi
                if (low[nbr] > tin[src]) {
                    ans.push_back({nbr, src});
                }
            } else {
                // Agar node visitedited hai aur parent nahi hai
                // Toh low value update karo
                low[src] = min(low[src], tin[nbr]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int>> adjList;
        
        // Adjacency list banao
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<vector<int>> ans;
        int timer = 0;
        vector<int> tin(n, -1);  // Time of insertion array
        vector<int> low(n, -1); // Lowest time array
        unordered_map<int, bool> visited; // visited nodes
        
        // DFS call karo bridges dhoondhne ke liye
        findBridges(0, -1, timer, tin, low, visited, ans, adjList);
        cout<< ans.size();
        return ans;
    }
};
