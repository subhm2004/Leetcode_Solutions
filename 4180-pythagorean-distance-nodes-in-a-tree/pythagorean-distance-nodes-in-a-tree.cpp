class Solution {
public:

    unordered_map<int, list<int>> adjList;

    void bfs(int src, vector<int>& dist) {

        queue<int> q;

        q.push(src);

        dist[src] = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto nbr : adjList[node]) {

                if (dist[nbr] == -1) {

                    dist[nbr] = dist[node] + 1;

                    q.push(nbr);
                }
            }
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

        adjList.clear();

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> distX(n, -1);
        vector<int> distY(n, -1);
        vector<int> distZ(n, -1);

        bfs(x, distX);
        bfs(y, distY);
        bfs(z, distZ);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            vector<long long> d = {
                distX[i],
                distY[i],
                distZ[i]
            };

            sort(d.begin(), d.end());

            long long a = d[0];
            long long b = d[1];
            long long c = d[2];

            if (a * a + b * b == c * c)
                ans++;
        }

        return ans;
    }
};