class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void union_by_rank(int x, int y) {
        int x_parent = find(x), y_parent = find(y);
        if (x_parent == y_parent)
            return;

        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};

class Solution {
public:
    bool is_possible(int n, vector<vector<int>>& edges, int k, int target) {
        UnionFind uf(n);
        int used = 0;

        // Step 1: mandatory edges pehle process karo
        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must != 1) continue;

            if (s < target) return false;               // mandatory edge target se kam → impossible

            if (uf.find(u) == uf.find(v)) return false; // cycle banega → invalid

            uf.union_by_rank(u, v);
            used++;
        }

        if (used == n - 1) return true; // sirf mandatory edges se spanning tree ban gaya

        // Step 2: optional edges collect karo jo target meet kar sakti hain
        // {needs_upgrade, u, v}
        // 0 = free, 1 = upgrade chahiye
        // sort isliye taaki free edges pehle use hon → upgrades bachao
        vector<tuple<int,int,int>> candidates;

        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 1) continue;

            if (s >= target)
                candidates.push_back({0, u, v});      // upgrade ki zarurat nahi
            else if (2 * s >= target)
                candidates.push_back({1, u, v});      // ek upgrade se kaam chalega
            // else: double karke bhi target nahi milta → skip
        }

        sort(candidates.begin(), candidates.end()); // {0,...} pehle, {1,...} baad mein

        // Step 3: greedy Kruskal — free edges pehle, upgrade wale baad
        int upgrades_used = 0;

        for (auto& [needs_upgrade, u, v] : candidates) {
            if (uf.find(u) == uf.find(v)) continue; // cycle banega → skip

            if (needs_upgrade) {
                upgrades_used++;
                if (upgrades_used > k) return false; // budget khatam
            }

            uf.union_by_rank(u, v);
            used++;
            if (used == n - 1) return true; // spanning tree complete
        }

        return false; // sab nodes connect nahi hue
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int low = 1, high = 2e5, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (is_possible(n, edges, k, mid)) {
                ans = mid;
                low = mid + 1;  // aur zyada stability possible hai kya?
            } else {
                high = mid - 1; // target bahut bada hai, kam karo
            }
        }

        return ans;
    }
};