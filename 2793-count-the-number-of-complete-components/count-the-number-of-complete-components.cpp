class Solution
{
public:
    // Graph ko adjacency list ke form me store karenge.
    unordered_map<int, list<int>> adjList;

    // ---------------------------------------------------------
    // Graph me undirected edge add karne ka function.
    // u <----> v
    // ---------------------------------------------------------
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // ---------------------------------------------------------
    // BFS function
    //
    // Return karega:
    // first  -> Total Nodes in Component
    // second -> Total Edges (Double Counted)
    // ---------------------------------------------------------
    pair<int, int> bfs(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;

        // Source node se BFS start
        q.push(src);
        visited[src] = true;

        int nodes = 0;
        int edges = 0;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            // Ek node visit ho gayi
            nodes++;

            // Degree add kar rahe hain.
            //
            // Example:
            // 0--1
            //
            // Node 0 degree = 1
            // Node 1 degree = 1
            //
            // Total edges variable = 2
            //
            // Matlab har edge do baar count hogi.
            edges += adjList[frontNode].size();

            // Saare neighbours ko visit karo.
            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return {nodes, edges};
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, bool> visited;

        // ---------------------------------------------------------
        // Step 1 : Graph Build karo.
        // ---------------------------------------------------------
        for (auto &edge : edges)
        {
            addEdge(edge[0], edge[1]);
        }

        int completeComponents = 0;

        // ---------------------------------------------------------
        // Step 2 :
        // Har unvisited node se BFS chalao.
        // Har BFS ek connected component dega.
        // ---------------------------------------------------------
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                auto [nodes, totalEdges] = bfs(i, visited);

                // Complete graph me
                //
                // Actual edges = n*(n-1)/2
                //
                // Lekin humne har edge 2 baar count ki hai.
                //
                // Isliye expected double count:
                //
                // n*(n-1)
                if (nodes * (nodes - 1) == totalEdges)
                {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};