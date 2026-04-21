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
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void UNION_BY_RANK(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py])
            parent[px] = py;

        else if (rank[px] > rank[py])
            parent[py] = px;

        else {
            parent[px] = py;
            rank[py]++;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source,
                               vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {

        int n = source.size();

        Union_find dsu(n);

        for (auto& edge : allowedSwaps)
            dsu.UNION_BY_RANK(edge[0], edge[1]);

        unordered_map<int, unordered_map<int, int>> group_frequency;

        for (int i = 0; i < n; i++) {
            int parent = dsu.find(i);

            group_frequency[parent][source[i]]++;
        }

        int mismatch = 0;

        for (int i = 0; i < n; i++) {
            int parent = dsu.find(i);

            if (group_frequency[parent][target[i]] > 0)
                group_frequency[parent][target[i]]--;
            else
                mismatch++;
        }

        return mismatch;
    }
};