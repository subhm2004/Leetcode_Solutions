/*
 * ═══════════════════════════════════════════════════════════════════
 *  DSU WITH PARITY — BIPARTITE GRAPH CHECKER
 *
 *  Idea: Normal DSU sirf "same group?" batata hai.
 *        Parity DSU yeh bhi batata hai: "same group ke do nodes ka
 *        COLOR alag hai ya same?"
 *
 *  parity[x] = x ka apne ROOT se color-distance (0 ya 1)
 *            = 0 → x aur root same color
 *            = 1 → x aur root alag color
 * ═══════════════════════════════════════════════════════════════════
 */
class DSU {
public:
    vector<int> parent, rank, parity;

    // ── Constructor ──────────────────────────────────────────────────
    // Har node apna khud ka parent hai (alag-alag sets)
    // rank   = tree ki height (union by rank ke liye)
    // parity = root se color distance (shuru mein 0 — root se same)
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        parity.resize(n, 0); // 0 = "main apne aap se same color hoon"

        for(int i = 0; i < n; i++)
            parent[i] = i; // har node khud ka root
    }

    // ── find() with Path Compression + Parity Update ──────────────────
    // Returns: {root, parity_of_x_relative_to_root}
    //
    // Chain example:  A → B → C  (C is root)
    //   parity[A] = 1 (A vs B alag)
    //   parity[B] = 1 (B vs C alag)
    //   find(A) call hone par:
    //     → find(B) recursively pehle chalega → returns {C, 1}
    //     → parity[A] ^= 1  →  parity[A] = 1^1 = 0
    //     → parent[A] = C  (path compression: shortcut seedha root tak)
    //     → return {C, 0}  ✓ (A aur C actually same color hain!)
    //
    // XOR kyun? Kyunki color chain transitive hai:
    //   A≠B aur B≠C  →  A==C  →  XOR: 1^1 = 0 ✓
    //   A≠B aur B==C →  A≠C  →  XOR: 1^0 = 1 ✓
    pair<int,int> find(int x) {
        if(parent[x] == x) return {x, 0}; // base case: root mila, distance = 0

        auto [root, p] = find(parent[x]); // parent ka root dhundo (recursive)

        parent[x] = root;   // PATH COMPRESSION: x seedha root se jod do
        parity[x] ^= p;     // PARITY UPDATE: x ka root-relative color fix karo
                             // (purana parity[x] = x→parent distance tha,
                             // ab XOR se x→root distance ban gaya)

        return {parent[x], parity[x]}; // {root, x ka root se color distance}
    }

    // ── unionByRank() — Edge (u,v) add karo + bipartite check ─────────
    // Returns: true  → edge valid hai (bipartite condition satisfy)
    //          false → u aur v SAME color ke hain (odd cycle!) → NOT bipartite
    //
    // Har edge u–v ka matlab: u aur v neighbors hain → colors ALAG hone chahiye
    // Isko enforce karna hi is function ka kaam hai.
    bool unionByRank(int u, int v) {
        auto [pu, xu] = find(u); // pu = u ka root, xu = u ki parity (0/1)
        auto [pv, xv] = find(v); // pv = v ka root, xv = v ki parity (0/1)

        // ── CASE 1: Already same set mein hain ─────────────────────────
        // Agar u aur v pehle se ek hi component mein hain,
        // to hum merge nahi kar sakte — sirf check karte hain:
        // kya unke colors ALAG hain? (bipartite condition)
        //
        //   xu ^ xv == 1  →  colors alag  → ✓ valid edge
        //   xu ^ xv == 0  →  colors same  → ✗ ODD CYCLE → not bipartite!
        if(pu == pv) {
            return ((xu ^ xv) == 1); // true = bipartite ok, false = cycle found!
        }

        // ── CASE 2: Alag sets → Merge by Rank ──────────────────────────
        // Union by rank: chote tree ko bade tree mein attach karo
        // → tree zyada tall nahi hoga → find() tez rahega
        //
        // parity[pu] = xu ^ xv ^ 1  kyun?
        //   Hum chahte hain: merge ke baad u aur v ke colors ALAG rahein
        //   After merge: color(u) = xu ^ parity[pu] (relative to pv)
        //   Condition: xu ^ parity[pu] ≠ xv
        //   Solve:     parity[pu] = xu ^ xv ^ 1
        //   The ^1 is the "flip" — ensure opposite colors for neighbors

        if(rank[pu] < rank[pv]) {
            // pu chhota tree hai → usse pv ke neeche attach karo
            parent[pu] = pv;
            parity[pu] = xu ^ xv ^ 1; // pv ke relative mein pu ki parity set karo
        }
        else if(rank[pu] > rank[pv]) {
            // pv chhota tree hai → usse pu ke neeche attach karo
            parent[pv] = pu;
            parity[pv] = xu ^ xv ^ 1; // pu ke relative mein pv ki parity set karo
        }
        else {
            // Dono same rank → koi bhi root ban sakta hai (pu choose kiya)
            // Rank badhta hai sirf tab jab dono equal ho
            parent[pv] = pu;
            parity[pv] = xu ^ xv ^ 1;
            rank[pu]++; // tree ek level aur deep ho gaya
        }

        return true; // merge successful, edge valid
    }
};

// ── Main Solution ──────────────────────────────────────────────────────
// Har edge (u, v) ke liye DSU mein add karo.
// Agar koi bhi edge invalid nikla → graph bipartite nahi hai.
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        DSU dsu(n); // n nodes ka DSU banao

        for(int u = 0; u < n; u++) {
            for(int v : graph[u]) {
                // Har neighbor v ke saath u ko merge karo
                // Agar merge fail → u aur v same color → odd cycle → false
                if(!dsu.unionByRank(u, v)) {
                    return false; // ODD CYCLE FOUND → not bipartite
                }
            }
        }

        return true; // Sab edges valid → graph bipartite hai!
    }
};