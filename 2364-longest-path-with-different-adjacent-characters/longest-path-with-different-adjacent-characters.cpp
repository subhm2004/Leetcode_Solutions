class Solution {
public:
    string s;
    unordered_map<int, list<int>> adjList;
    int ans;

    int dfs(int curr_node, int par) {
        int longest = 0;
        int second_longest = 0;

        for (int child : adjList[curr_node]) {
            if (child == par)
                continue;

            int child_longest_length = dfs(child, curr_node);

            if (s[child] == s[curr_node]) // same char toh count mat karo
                continue;

            if (child_longest_length > longest) {
                second_longest = longest;
                longest = child_longest_length;
            } else if (child_longest_length > second_longest) {
                second_longest = child_longest_length;
            }
        }

        int neeche_hi_milgaya_answer = longest + second_longest + 1;
        int koi_ek_acha = max(longest, second_longest) + 1;
        int only_root_acha = 1;

        ans = max({ans, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});

        return max(koi_ek_acha, only_root_acha);
    }

    int longestPath(vector<int>& parent, string s) {
        this->s = s;
        this->ans = 1;
        int n = parent.size();

        for (int i = 1; i < n; i++) {
            int p = parent[i];
            adjList[p].push_back(i);
            adjList[i].push_back(p);
        }

        dfs(0, -1);

        return ans; 
    }
};