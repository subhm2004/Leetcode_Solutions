typedef long long ll;

class Solution {
public:
    unordered_map<int, list<pair<int, ll>>> adjList;
    unordered_map<string, ll> dp2;   // (start,end) for dijkstra

    ll dijkstra_algo(int start, int end, int total_nodes) {

        string key = to_string(start) + "#" + to_string(end);

        if (dp2.count(key))
            return dp2[key];

        vector<ll> dist(total_nodes, LLONG_MAX);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {

            auto [curr_cost, node] = pq.top();
            pq.pop();

            if (curr_cost > dist[node])
                continue;

            if (node == end) {
                return dp2[key] = curr_cost;
            }

            for (auto& nbr : adjList[node]) {

                int nbr_node = nbr.first;
                ll wt = nbr.second;

                ll new_cost = curr_cost + wt;

                if (new_cost < dist[nbr_node]) {
                    dist[nbr_node] = new_cost;
                    pq.push({new_cost, nbr_node});
                }
            }
        }

        return dp2[key] = LLONG_MAX;
    }

    ll solve(int idx, string& source, string& target, vector<ll>& dp,
             vector<int>& lens, unordered_map<string, int>& mp,
             int total_nodes) {

        int N = source.size();

        if (idx == N)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        const ll INF = 1e15;
        ll ans = INF;

        if (source[idx] == target[idx]) {
            ans = solve(idx + 1, source, target, dp, lens, mp, total_nodes);
        }

        for (int len : lens) {

            if (idx + len > N)
                break;

            string s = source.substr(idx, len);
            string t = target.substr(idx, len);

            if (!mp.count(s) || !mp.count(t))
                continue;

            int u = mp[s];
            int v = mp[t];

            ll c = dijkstra_algo(u, v, total_nodes);

            if (c == LLONG_MAX)
                continue;

            ll rest = solve(idx + len, source, target, dp, lens, mp, total_nodes);
            if (rest == INF)
                continue;

            ans = min(ans, c + rest);
        }

        return dp[idx] = ans;
    }

    long long minimumCost(string source, string target,
                           vector<string>& original,
                           vector<string>& changed,
                           vector<int>& cost) {

        int N = source.size();
        const ll INF = 1e15;

        unordered_map<string, int> mp;
        int node_count = 0;

        for (int i = 0; i < original.size(); i++) {
            if (!mp.count(original[i]))
                mp[original[i]] = node_count++;
            if (!mp.count(changed[i]))
                mp[changed[i]] = node_count++;
        }

        adjList.clear();
        dp2.clear();

        vector<int> lens;
        set<int> st;

        for (int i = 0; i < original.size(); i++) {

            int u = mp[original[i]];
            int v = mp[changed[i]];

            adjList[u].push_back({v, cost[i]});
            st.insert(original[i].size());
        }

        for (int x : st)
            lens.push_back(x);

        vector<ll> dp(N + 1, -1);

        ll res = solve(0, source, target, dp, lens, mp, node_count);

        if (res >= INF)
            return -1;
        return res;
    }
};
