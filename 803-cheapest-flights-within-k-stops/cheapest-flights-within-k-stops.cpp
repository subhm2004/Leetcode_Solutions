class Solution {
public:
    // T tuple ka matlab:
    // cost  -> ab tak ka total travel cost
    // city  -> current city jahan hum khade hain
    // stops -> ab tak kitni flights (edges) use ho chuki hain
    using T = tuple<int, int, int>; // (cost, city, stops)

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // Adjacency list:
        // adjList[u] = list of {v, w}
        // matlab u se v jane ki flight hai with cost w
        unordered_map<int, list<pair<int,int>>> adjList;

        // flights array se graph build kar rahe hain
        for (auto &f : flights) {
            int u = f[0];  // source city
            int v = f[1];  // destination city
            int w = f[2];  // flight cost
            adjList[u].push_back({v, w});
        }

        // Min-heap (priority queue)
        // smallest cost wala state pehle niklega
        priority_queue<T, vector<T>, greater<T>> pq;

        // Start state:
        // cost = 0, city = src, stops = 0
        pq.emplace(0, src, 0);

        // dist[i] ka matlab:
        // city i tak pahunchne ke liye minimum stops ab tak kitne lage
        vector<int> dist(n, INT_MAX);

        // source city pe 0 stops lage hain
        dist[src] = 0;

        // Jab tak pq empty nahi hota
        while (!pq.empty()) {

            // sabse kam cost wala state nikaal lo
            auto [cost, city, stops] = pq.top();
            pq.pop();

            // Agar destination mil gaya
            // kyunki pq cost ke basis pe hai,
            // ye cheapest possible answer hoga
            if (city == dst)
                return cost;

            // Agar stops limit cross ho gayi
            // (k stops allowed hain, to k+1 flights max)
            if (stops > k)
                continue;

            // Agar hum is city pe pehle hi
            // kam stops ke saath aa chuke hain,
            // to is path ka koi fayda nahi
            if (dist[city] < stops)
                continue;

            // Update kar do ki city pe itne stops lage
            dist[city] = stops;

            // Ab current city ke saare neighbours explore karo
            for (auto &[v, w] : adjList[city]) {

                // naya cost = purana cost + flight cost
                int new_cost  = cost + w;

                // ek aur flight use hui
                int new_stops = stops + 1;

                // next state pq me daal do
                pq.emplace(new_cost, v, new_stops);
            }
        }

        // Agar destination tak nahi pahunch paaye
        return -1;
    }
};