class Solution {
public:

    unordered_map<int, list<int>> adjList;

    void topo_sort_BFS(int n, vector<int>& topo_sort)
    {
        queue<int> q;

        vector<int> indegree(n, 0);

        // indegree calculate krte hai 
        for(auto &it : adjList)
        {
            for(auto &nbr : it.second)
            {
                indegree[nbr]++;
            }
        }

        // jis node ki indegree 0 ho gyi h use queue me dal diya
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int front_Node = q.front();

            q.pop();

            topo_sort.push_back(front_Node);

            for(auto &nbr : adjList[front_Node])
            {
                indegree[nbr]--;

                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer,
                            vector<int>& quiet) {

        int n = quiet.size();

        // poor -> rich
        for(auto &edge : richer)
        {
            int rich = edge[0];
            int poor = edge[1];

            adjList[poor].push_back(rich);
        }

        vector<int> topo_sort;

        topo_sort_BFS(n, topo_sort);

        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            ans[i] = i;
        }

        // reverse topo process
        for(int i = topo_sort.size() - 1; i >= 0; i--)
        {
            int node = topo_sort[i];

            for(auto &richer_person : adjList[node])
            {
                if(quiet[ans[richer_person]] < quiet[ans[node]])
                {
                    ans[node] = ans[richer_person];
                }
            }
        }

        return ans;
    }
};