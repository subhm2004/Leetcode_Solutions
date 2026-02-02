using ll = long long;
unordered_map<int, list<pair<int, int>>> adjList;
class BIT {
public:
    int n;
    vector<ll> bit;

    BIT(int n) {
        this->n = n;
        bit.assign(n + 2, 0);
    }

    void update(int i, ll x) {
        for (; i <= n; i += (i & -i))
            bit[i] += x;
    }

    ll sum_query(int i) {
        ll s = 0;
        for (; i > 0; i -= (i & -i))
            s += bit[i];
        return s;
    }
};
class Euler_Tour {
public:
    vector<int> start, end, depth;
    vector<ll> base_dist;
    int timer, n;

    Euler_Tour(int n) : n(n) {
        start.assign(n + 1, 0);
        end.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        base_dist.assign(n + 1, 0);
        timer = 0;
    }

    void dfs(int u, int p) {
        start[u] = ++timer;

        for (auto& pr : adjList[u]) {
            int v = pr.first;
            int w = pr.second;
            if (v == p)
                continue;

            depth[v] = depth[u] + 1;
            base_dist[v] = base_dist[u] + w;

            dfs(v, u);
        }

        end[u] = timer;
    }
};
long long make_key(int u, int v) {
    if (u > v)
        swap(u, v);
    return ((ll)u << 32) | v;
}

class Solution {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        adjList.clear();

        unordered_map<ll, int> edge_weight;
        unordered_map<ll, int> edge_child;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});

            edge_weight[make_key(u, v)] = w;
        }

        Euler_Tour et(n);
        et.depth[1] = 0;
        et.base_dist[1] = 0;
        et.dfs(1, 0);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int child = (et.depth[u] > et.depth[v]) ? u : v;
            edge_child[make_key(u, v)] = child;
        }

        BIT bit(n);
        vector<int> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int u = q[1];
                int v = q[2];
                int new_w = q[3];

                ll key = make_key(u, v);

                int old = edge_weight[key];
                int diff = new_w - old;
                
                edge_weight[key] = new_w;

                int child = edge_child[key];
                int l = et.start[child];
                int r = et.end[child];

                bit.update(l, diff);
                bit.update(r + 1, -diff);
            } else {
                int x = q[1];
                ll extra = bit.sum_query(et.start[x]);
                ll dist = et.base_dist[x] + extra;
                ans.push_back((int)dist);
            }
        }

        return ans;
    }
};
