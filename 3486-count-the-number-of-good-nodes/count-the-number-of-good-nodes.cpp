class Solution {
public:
    unordered_map<int, list<int>> adjList;
    int ans = 0;

    int dfs(int node, int parent) {

        int sub_tree_size = 1;

        int prev_child_Size = -1;
        bool is_good_node = true;

        for (auto child : adjList[node]) {

            if (child == parent)
                continue;

            int curr_child_size = dfs(child, node);

            if (prev_child_Size == -1) {
                prev_child_Size = curr_child_size;
            }
            else if (prev_child_Size != curr_child_size) {
                is_good_node = false;
            }

            sub_tree_size += curr_child_size;
        }

        if (is_good_node)
            ans++;

        return sub_tree_size;
    }

    int countGoodNodes(vector<vector<int>>& edges) {

        adjList.clear();
        ans = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(0, -1);

        return ans;
    }
};