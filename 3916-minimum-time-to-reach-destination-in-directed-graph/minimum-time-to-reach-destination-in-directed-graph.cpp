using P = pair<long long, int>; // P = {time, node} 
class Solution {
public:
    unordered_map<int,list<tuple<int, int,int>>>adjList;

        long long dijkstra(int n) {

        // min_time[i] = node i tak pahunchne ka minimum time
        vector<long long> min_time(n, 1e18);

        // min-heap
        priority_queue<P, vector<P>, greater<>> pq;

        // node 0 pe time 0 pe hain
        min_time[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [curr_time, node] = pq.top();
            pq.pop();

            // stale state: pehle better path mil chuka hai, skip karo
            if (curr_time > min_time[node])
                continue;

            if (node == n - 1)
                return curr_time;

            for (auto& [nbr, start, end] : adjList[node]) {
                // CASE 1: edge ka window close ho gaya — kabhi use nahi ho sakti (SKIP)

                if (curr_time > end)
                    continue;

                long long next_time;

                if (curr_time < start) {
                    // CASE 2: edge abhi valid nahi — start tak wait karo
                    // start pe chalte hain → arrive at start + 1
                    next_time = start + 1;
                } else {
                    // CASE 3: start <= curr_time <= end — seedha move karo
                    next_time = curr_time + 1;
                }

                // relaxation: naya path better hai toh update krte hai 
                if (next_time < min_time[nbr]) {
                    min_time[nbr] = next_time; 
                    pq.push({next_time, nbr}); 
                }
            }
        }

        // pq khali ho gayi, node n-1 kabhi reach nahi hua
        return -1;
    }

    int minTime(int n, vector<vector<int>>& edges) {

        // directed graph build krte h
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int start = edge[2];  
            int end = edge[3];    

            // u → v edge, sirf [start, end] window mein valid
            adjList[u].push_back({v, start, end});
        }

        return dijkstra(n);
    }
};