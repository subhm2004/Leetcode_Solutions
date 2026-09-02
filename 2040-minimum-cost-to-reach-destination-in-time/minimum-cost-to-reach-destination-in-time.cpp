class Solution {
public:
    // (cost, node, time) — priority_queue me tuple ka lexicographic
    // comparison hota hai, isliye cost ko sabse pehle rakha hai
    // taaki min-heap cost ke hisaab se pop kare.
    using T = tuple<int, int, int>;

    // adjacency list: node -> list of {neighbour, travelTime}
    unordered_map<int, list<pair<int, int>>> adjList;

    vector<vector<int>> dijkstra(
        int n,
        int maxTime,
        vector<int>& fees
    ) {
        const int INF = 1e9;

        // KEY IDEA: yahan state sirf "node" nahi hai, balki
        // (node, timeSpent) pair hai. Kyunki ek node par kam cost
        // se pahunchna hamesha better nahi — ho sakta hai woh path
        // zyada time le raha ho aur aage jaake maxTime cross kar de.
        // Isliye har (node, time) combination ka apna best cost.
        //
        // dist[u][t] = city u tak t minutes exactly kharch karke
        //              pahunchne ki minimum total fee
        vector<vector<int>> dist(
            n, vector<int>(maxTime + 1, INF)
        );

        // {cost, node, time}
        priority_queue<
            T,
            vector<T>,
            greater<T>          // greater => min-heap
        > pq;

        // Start: city 0 par 0 minute me, cost = uski apni fee
        // (source ki fee bhi count hoti hai)
        dist[0][0] = fees[0];

        pq.push({fees[0], 0, 0});

        while (!pq.empty()) {

            auto [cost, u, time] = pq.top();
            pq.pop();

            // Lazy deletion: agar ye entry stale hai (baad me isi
            // (u, time) state ke liye better cost mil gaya tha),
            // to skip kar do. Isse decrease-key ki zaroorat nahi padti.
            if (cost != dist[u][time])
                continue;

            // NOTE: adjList[u] — unordered_map par operator[] use kar
            // rahe ho, to missing key ke liye empty list insert ho
            // jaayegi. Yahan harmless hai, bas dhyan rahe.
            for (auto &[v, travelTime] : adjList[u]) {

                int newTime = time + travelTime;

                // Time budget cross ho gaya => ye branch useless hai.
                // Yahi pruning pure algorithm ko bounded rakhti hai.
                if (newTime > maxTime)
                    continue;

                // v par pahunche, to v ki passing fee dena padegi
                int newCost = cost + fees[v];

                // Standard relaxation, but (v, newTime) state ke liye
                if (newCost < dist[v][newTime]) {

                    dist[v][newTime] = newCost;

                    pq.push({
                        newCost,
                        v,
                        newTime
                    });
                }
            }
        }

        return dist;
    }

    int minCost(
        int maxTime,
        vector<vector<int>>& edges,
        vector<int>& passingFees
    ) {
        int n = passingFees.size();

        // multiple test cases (LeetCode ek hi object reuse karta hai)
        // ke liye graph reset karna zaroori hai
        adjList.clear();

        // Undirected graph => dono direction me edge daalo.
        // Multi-edges allowed hain, aur list me dono rakh lena
        // theek hai — Dijkstra khud hi best wali choose kar lega.
        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int time = edge[2];

            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }

        vector<vector<int>> dist =
            dijkstra(n, maxTime, passingFees);

        int ans = 1e9;

        // Destination par kisi bhi valid time (0..maxTime) par
        // pahunch sakte ho — un sab me se minimum cost chahiye.
        for (int time = 0; time <= maxTime; time++) {
            ans = min(ans, dist[n - 1][time]);
        }

        // INF matlab reachable hi nahi tha within maxTime
        return ans == 1e9 ? -1 : ans;
    }
};