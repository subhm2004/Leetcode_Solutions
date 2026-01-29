// class Solution { // priority queue Solution
// public:
//     // T tuple ka matlab:
//     // cost  -> ab tak ka total travel cost
//     // city  -> current city jahan hum khade hain
//     // stops -> ab tak kitni flights (edges) use ho chuki hain
//     using T = tuple<int, int, int>; // (cost, city, stops)

//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

//         unordered_map<int, list<pair<int,int>>> adjList;

//         for (auto &f : flights) {
//             int u = f[0];  // source city
//             int v = f[1];  // destination city
//             int w = f[2];  // flight cost
//             adjList[u].push_back({v, w});
//         }

//         // Min-heap (priority queue)
//         priority_queue<T, vector<T>, greater<>> pq;

//         // Start state: cost = 0, city = src, stops = 0
//         pq.emplace(0, src, 0);

//         // dist[i] ka matlab: city i tak pahunchne ke liye minimum stops ab tak kitne lage
//         vector<int> dist(n, INT_MAX);

//         // source city pe 0 stops lage hain
//         dist[src] = 0;

//         // Jab tak pq empty nahi hota
//         while (!pq.empty()) {

//             // sabse kam cost wala state nikaal lo
//             auto [cost, city, stops] = pq.top();
//             pq.pop();

//             // Agar destination mil gaya kyunki pq cost ke basis pe hai, ye cheapest possible answer hoga
//             if (city == dst)
//                 return cost;

//             // Agar stops limit cross ho gayi
//             if (stops > k)
//                 continue;

//             // Agar hum is city pe pehle hi kam stops ke saath aa chuke hain, to is path ka koi fayda nahi
//             if (dist[city] < stops)
//                 continue;

//             // Update kar do ki city pe itne stops lage
//             dist[city] = stops;

//             // Ab current city ke saare neighbours explore karo
//             for (auto &[v, w] : adjList[city]) {

//                 // naya cost = purana cost + flight cost
//                 int new_cost  = cost + w;

//                 // ek aur flight use hui
//                 int new_stops = stops + 1;

//                 // next state pq me daal do
//                 // pq.push_back({new_cost, v, new_stops});

//                 pq.emplace(new_cost, v, new_stops);
//             }
//         }

//         // Agar destination tak nahi pahunch paaye
//         return -1;
//     }
// };


// Bellmann Ford Solution
// Bellman–Ford best hai kyunki ye fixed number of edges (stops) ke saath shortest path nikalta hai, aur is problem me exactly wahi constraint hai.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[src] = 0;

        // At most k stops ⇒ at most k+1 edges
        for (int i = 0; i <= k; i++) {
            vector<long long> temp = dist;

            for (auto &f : flights) {
                int u = f[0];
                int v = f[1];
                int w = f[2];

                if (dist[u] != INF && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }

        return dist[dst] == INF ? -1 : (int)dist[dst];
    }
};

