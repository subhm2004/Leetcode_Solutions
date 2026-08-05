class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        unordered_map<int, list<int>> adjList;

        // Graph banao
        for (auto &e : invocations)
        {
            adjList[e[0]].push_back(e[1]);
        }

        // Find all suspicious methods
        vector<int> suspicious(n, 0);

        queue<int> q;
        q.push(k);
        suspicious[k] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto nbr : adjList[node])
            {
                if (!suspicious[nbr])
                {
                    suspicious[nbr] = 1;
                    q.push(nbr);
                }
            }
        }

        // Check if any non-suspicious method invokes a suspicious method
        for (auto &e : invocations)
        {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v])
            {
                vector<int> ans;

                for (int i = 0; i < n; i++)
                {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        // Remaining methods
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (!suspicious[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};