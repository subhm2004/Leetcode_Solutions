class Solution {
public:

    vector<bool> sieve_of_eratosthenes(int n)
    {
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;
            }
        }
        return isPrime;
    }

    int minOperations(int n, int m)
    {
        vector<bool> isPrime = sieve_of_eratosthenes(10000);

        if (isPrime[n] || isPrime[m]) return -1;

        string a = to_string(n);
        string b = to_string(m);
        if (a.size() != b.size()) return -1;

        int len = a.size();

        unordered_map<int, list<pair<int,int>>> adjList;
        // pair : {nextNode , cost}

        // -----------------------------
        // Build graph
        // -----------------------------
        for (int x = 0; x < 10000; x++)
        {
            if (isPrime[x]) continue;

            string s = to_string(x);
            if ((int)s.size() != len) continue;

            for (int i = 0; i < len; i++)
            {
                int d = s[i] - '0';

                // increase
                if (d < 9)
                {
                    string t = s;
                    t[i] = char('0' + d + 1);

                    if (t[0] != '0')
                    {
                        int v = stoi(t);
                        if (!isPrime[v])
                            adjList[x].push_back({v, v});
                    }
                }

                // decrease
                if (d > 0)
                {
                    string t = s;
                    t[i] = char('0' + d - 1);

                    if (t[0] != '0')
                    {
                        int v = stoi(t);
                        if (!isPrime[v])
                            adjList[x].push_back({v, v});
                    }
                }
            }
        }

        // -----------------------------
        // Dijkstra
        // -----------------------------
        const long long INF = 1e18;
        vector<long long> dist(10000, INF);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[n] = n;
        pq.push({n, n});

        while (!pq.empty())
        {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost != dist[u]) continue;

            if (u == m)
                return cost;

            for (auto &edge : adjList[u])
            {
                int v = edge.first;
                int w = edge.second;   // yaha w = v

                if (dist[v] > cost + w)
                {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};
