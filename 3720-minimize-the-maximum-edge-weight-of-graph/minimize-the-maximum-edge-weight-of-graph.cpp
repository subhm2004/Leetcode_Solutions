class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, list<pair<int, int>>> adjList;

        // Reverse adjacency list banana (using list instead of vector)
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            adjList[b].push_back({a, w});
        }

        int ans = 0;
        vector<bool> visited(n, false);  // Visit track karne ke liye
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});  // Start from node 0 with weight 0

        while (!pq.empty()) {
            auto [w, node] = pq.top();
            pq.pop();

            if (visited[node]) continue;
            visited[node] = true;

            ans = max(ans, w);  // Max weight track karo

            for (auto& [nbr, wei] : adjList[node]) {
                pq.push({wei, nbr});
            }
        }

        // Check agar koi node unvisited hai
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) return -1;
        }

        return ans;
    }
};

//USING DIJKSTRAS ALGORITHM 
// class Solution {
// public:
//     // Ye function check karega ki kya sabhi nodes node 0 tak pahunch sakte hain given maxWeight ke andar
//     bool canReachUsingDijkstra(int n, unordered_map<int, vector<pair<int, int>>>& adjList, int maxWeight) {
//         vector<int> dist(n, INT_MAX);  // Sabhi nodes ka distance initialize kiya INT_MAX se
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min heap (priority queue)

//         dist[0] = 0;  // Start node ka distance 0 hoga
//         pq.push({0, 0});  // Start node ko queue me push kiya

//         while (!pq.empty()) {
//             auto [currDist, node] = pq.top();  // Current node aur uska distance nikal rahe hain
//             pq.pop();

//             // Agar koi behtar distance mil chuka hai to is node ko skip kar do
//             if (currDist > dist[node]) 
//                 continue;

//             // Sare nbrghbors ko check kar rahe hain
//             for (auto& [nbrghbor, weight] : adjList[node]) {
//                 if (weight <= maxWeight) { // Sirf unhi edges ko consider kare jo maxWeight ke andar hain
//                     int newDist = max(currDist, weight); // nbrghbor tak pahunchne ka distance calculate kiya
//                     if (newDist < dist[nbrghbor]) {  // Agar naye distance se improvement ho raha hai to update karo
//                         dist[nbrghbor] = newDist;
//                         pq.push({newDist, nbrghbor});  // Naya distance queue me push karo
//                     }
//                 }
//             }
//         }

//         // Check karo ki kya sabhi nodes reachable hain
//         for (int i = 0; i < n; ++i) {
//             if (dist[i] == INT_MAX) {
//                 return false; // Agar koi node unreachable hai to false return karo
//             }
//         }

//         return true;  // Agar sab reachable hain to true return karo
//     }

//     // Ye function minimum maxWeight calculate karega
//     int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
//         int left = 1, right = 0;

//         // Sabse bada edge weight find kar rahe hain
//         for (auto& e : edges) {
//             right = max(right, e[2]);  // Maximum edge weight ko store kar rahe hain
//         }

//         int result = -1;

//         // Binary search ka use karke minimum maxWeight find karenge
//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             // Adjacency list banayenge (reverse edges)
//             unordered_map<int, vector<pair<int, int>>> adj;
//             for (auto& edge : edges) {
//                 int a = edge[0], b = edge[1], w = edge[2];
//                 if (w <= mid) {
//                     adj[b].push_back({a, w}); // Reverse direction taki reachability node 0 tak ho
//                 }
//             }

//             // Check karenge ki sabhi nodes node 0 tak pahunch sakte hain ya nahi
//             if (canReachUsingDijkstra(n, adj, mid)) {
//                 result = mid;  // Agar reachable hai to result update karo
//                 right = mid - 1;  // Chhoti value ke liye try karo
//             } else {
//                 left = mid + 1;  // Badi value ke liye try karo
//             }
//         }

//         return result;  // Final result return karo
//     }
// };


