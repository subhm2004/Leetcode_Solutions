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

    bool unionByRank(int u, int v) {
        auto [pu, xu] = find(u);
        auto [pv, xv] = find(v);

        if(pu == pv) {
            return ((xu ^ xv) == 1);
        }

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
            parity[pu] = xu ^ xv ^ 1;
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            parity[pv] = xu ^ xv ^ 1;
        }
        else {
            parent[pv] = pu;
            parity[pv] = xu ^ xv ^ 1;
            rank[pu]++;
        }

        return true;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        DSU dsu(n);

        for(int u = 0; u < n; u++) {
            for(int v : graph[u]) {
                if(!dsu.unionByRank(u, v)) {
                    return false;
                }
            }
        }

        return true;
    }
};