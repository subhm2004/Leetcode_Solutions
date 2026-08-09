class Solution {
public:
    unordered_map<int, list<int>> adjList;
    long long ans = 0;
    auto create_tree(vector<int>& parent) {

        unordered_map<int, list<int>> adjList;

        for (int i = 1; i < parent.size(); i++) {
            adjList[parent[i]].push_back(i);
        }

        return adjList;
    }

    int height(int node) {

        int h = 1;

        for (auto child : adjList[node]) {
            h = max(h, 1 + height(child));
        }

        return h;
    }

    void dfs(int node, int depth, int h, vector<int>& nums) {

        ans += 1LL * nums[node] * (h - depth + 1);

        for (auto child : adjList[node]) {
            dfs(child, depth + 1, h, nums);
        }
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        adjList = create_tree(parent);

        int h = height(0);

        ans = 0;

        dfs(0, 1, h, nums);

        return ans;
    }
};