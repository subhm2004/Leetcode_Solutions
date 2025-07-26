class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void union_by_rank(int x, int y) {
        int x_parent = find(x), y_parent = find(y);
        if (x_parent == y_parent) return;

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

class KruskalAlgorithm {
public:
    vector<vector<int>> edges;

    void add_edge(int u, int v, int weight, int original_index) {
        edges.push_back({u, v, weight, original_index});
    }

    int get_mst_weight(int n, vector<tuple<int, int, int>> extra_edges, int exclude_edge_index) {
        vector<vector<int>> sorted_edges = edges;
        sort(sorted_edges.begin(), sorted_edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        UnionFind uf(n);
        int mst_weight = 0, edge_count = 0;

        for (auto& edge : extra_edges) {
            int u = get<0>(edge), v = get<1>(edge), weight = get<2>(edge);
            if (uf.find(u) != uf.find(v)) {
                uf.union_by_rank(u, v);
                mst_weight += weight;
                edge_count++;
            }
        }

        for (const auto& edge : sorted_edges) {
            if (edge[3] == exclude_edge_index) continue;

            int u = edge[0], v = edge[1], weight = edge[2];
            if (uf.find(u) != uf.find(v)) {
                uf.union_by_rank(u, v);
                mst_weight += weight;
                edge_count++;
                if (edge_count == n - 1) break;
            }
        }

        return edge_count == n - 1 ? mst_weight : INT_MAX;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        KruskalAlgorithm kruskal;
        vector<int> critical_edges, pseudo_critical_edges;

        for (int i = 0; i < edges.size(); i++) {
            kruskal.add_edge(edges[i][0], edges[i][1], edges[i][2], i);
        }

        int original_mst_weight = kruskal.get_mst_weight(n, {}, -1);

        for (int i = 0; i < edges.size(); i++) {
            int weight_without_edge = kruskal.get_mst_weight(n, {}, i);

            if (weight_without_edge > original_mst_weight) {
                critical_edges.push_back(i);
            } else {
                int weight_with_edge = kruskal.get_mst_weight(
                    n, {{edges[i][0], edges[i][1], edges[i][2]}}, -1
                );

                if (weight_with_edge == original_mst_weight) {
                    pseudo_critical_edges.push_back(i);
                }
            }
        }

        return {critical_edges, pseudo_critical_edges};
    }
};
