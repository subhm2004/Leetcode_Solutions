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

    // Returns false if cycle detected
    bool union_by_rank(int x, int y) {
        int xp = find(x), yp = find(y);
        if (xp == yp) return false;

        if (rank[xp] < rank[yp])       parent[xp] = yp;
        else if (rank[xp] > rank[yp])  parent[yp] = xp;
        else { parent[xp] = yp; rank[yp]++; }

        return true;
    }
};

class Solution {
public:
    bool is_possible(int n, vector<vector<int>>& edges, int k, int target) {
        UnionFind uf(n);
        int used = 0;

        // Step 1: mandatory edges
        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must != 1) continue;

            if (s < target)               return false; // can't upgrade mandatory
            if (!uf.union_by_rank(u, v))  return false; // cycle
            used++;
        }

        if (used == n - 1) return true;

        // Step 2: collect optional candidates
        // {need_upgrade, u, v} — sort so free edges come first
        vector<tuple<int,int,int>> candidates;

        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 1) continue;

            if (s >= target)
                candidates.push_back({0, u, v});
            else if (2 * s >= target)
                candidates.push_back({1, u, v});
        }

        sort(candidates.begin(), candidates.end()); // free (0) before upgrade (1)

        // Step 3: greedy Kruskal
        int upgrades_used = 0;

        for (auto& [need_upgrade, u, v] : candidates) {
            if (!uf.union_by_rank(u, v)) continue; // cycle → skip

            if (need_upgrade) {
                upgrades_used++;
                if (upgrades_used > k) return false;
            }

            used++;
            if (used == n - 1) return true;
        }

        return false;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int low = 1, high = 2e5, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (is_possible(n, edges, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};