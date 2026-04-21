class Union_find {
        vector<int> parent;
        vector<int> rank;

    public:
        Union_find(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (x == parent[x])
                return x;

            return parent[x] = find(parent[x]);
        }

        void UNION_BY_RANK(int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent)
                return;

            if (rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            }
            else if (rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            }
            else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }
    };
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        Union_find dsu(n);

        for (auto& edge : allowedSwaps)
            dsu.UNION_BY_RANK(edge[0], edge[1]);

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            int parent = dsu.find(i);
            groups[parent].push_back(i);
        }

        int miss_matched = 0;

        for (auto& group : groups) {
            unordered_map<int, int> freq;

            for (int idx : group.second)
                freq[source[idx]]++;

            for (int idx : group.second) {
                if (freq[target[idx]] > 0)
                    freq[target[idx]]--;
                else
                    miss_matched++;
            }
        }

        return miss_matched;
    }
};