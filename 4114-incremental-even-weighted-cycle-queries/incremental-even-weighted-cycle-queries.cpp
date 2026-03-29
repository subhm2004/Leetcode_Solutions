class DSU {
public:
    vector<int> parent, rank_, parity;

    DSU(int n) {
        parent.resize(n);
        rank_.resize(n, 0);
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

    // w = edge weight (0 ya 1)
    // Returns: true  → edge valid (even cycle maintain)
    //          false → odd weight cycle banega → reject
    bool unionByRank(int u, int v, int w) {
        auto [pu, xu] = find(u);
        auto [pv, xv] = find(v);

        // ── CASE 1: Same component → sirf check karo ──────────────────
        // Cycle banega → check karo weight sum even hai ya nahi
        //
        // Condition: xu ^ xv == w hona chahiye
        //   xu ^ xv = existing parity between u and v (path se)
        //   w        = naye edge ka weight
        //   XOR dono = total cycle parity
        //   0 hona chahiye → even cycle
        //
        // Normal bipartite mein w=1 hamesha tha isliye xu^xv==1 check tha
        // Yahan w variable hai isliye xu^xv==w check karo
        if(pu == pv) {
            return ((xu ^ xv) == w); // true=even cycle, false=odd cycle
        }

        // ── CASE 2: Alag components → Merge karo ──────────────────────
        //
        // Normal mein tha:  parity[pu] = xu ^ xv ^ 1  (1 = hamesha flip)
        // Weighted mein:    parity[pu] = xu ^ xv ^ w  (w ke hisaab se flip)
        //
        // Kyun? Hum chahte hain merge ke baad:
        //   color(u) aur color(v) ka difference = w ho
        //   xu ^ parity[pu] ^ xv = w
        //   parity[pu] = xu ^ xv ^ w  ✓

        if(rank_[pu] < rank_[pv]) {
            parent[pu] = pv;
            parity[pu] = xu ^ xv ^ w;
        }
        else if(rank_[pu] > rank_[pv]) {
            parent[pv] = pu;
            parity[pv] = xu ^ xv ^ w;
        }
        else {
            parent[pv] = pu;
            parity[pv] = xu ^ xv ^ w;
            rank_[pu]++;
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

            // unionByRank:
            //   same component → check karo cycle even hai
            //   diff component → merge karo, hamesha valid
            if(dsu.unionByRank(u, v, w)) {
                ans++;
            }
            // false aaya → odd cycle → edge skip
        }

        return ans;
    }
};