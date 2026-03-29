class DSU {
public:
    vector<int> parent, rank, parity;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        parity.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    pair<int,int> find(int x) {
        if(parent[x] == x) return {x, 0};

        auto [root, p] = find(parent[x]);
        parent[x] = root;
        parity[x] ^= p;

        return {parent[x], parity[x]};
    }

    bool unionByRank(int u, int v, int w) {
        auto [pu, xu] = find(u);
        auto [pv, xv] = find(v);

        if(pu == pv) {
            return ((xu ^ xv) == w);
        }

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
            parity[pu] = xu ^ xv ^ w;
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            parity[pv] = xu ^ xv ^ w;
        }
        else {
            parent[pv] = pu;
            parity[pv] = xu ^ xv ^ w;
            rank[pu]++;
        }

        return true;
    }
};

class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int ans = 0;

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dsu.unionByRank(u, v, w)) {
                ans++;
            }
        }

        return ans;
    }
};