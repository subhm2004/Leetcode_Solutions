typedef long long ll;
class Solution {
 public:
   int dijkstra(unordered_map<int, list<pair<int, int>>>& adjList, int n, int src, int dst) {
    constexpr int MOD = 1e9+7;
    vector<ll> ways(n, 0); // Har node tak pahunchne ke total tareeke store karne ke liye
    vector<ll> dist(n, LLONG_MAX); // Har node tak ka shortest distance track karne ke liye

    ways[src] = 1; // Source node tak pahunchne ka ek hi tareeka hai (khud se start karna)
    dist[src] = 0; // Source node ka distance khud se 0 hoga
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> minHeap;
    minHeap.emplace(0, src); // Min heap me source node daal diya

    while (!minHeap.empty()) {
      auto [d, u] = minHeap.top();  // Structured binding se minHeap ka top element extract kiya
      minHeap.pop(); // Heap se top element hata diya

      if (d > dist[u]) continue; // Agar yeh distance purane distance se bada hai toh ignore karo

      for (auto& [v, w] : adjList[u]) { // u se connected har neighbor v ko check karo
        if (d + w < dist[v]) { // Agar naye distance se pahunchna better hai toh update karo
          dist[v] = d + w;
          ways[v] = ways[u]; // naye distance ke corresponding ways update karo
          minHeap.emplace(dist[v], v); // naye distance ke sath neighbor ko heap me daalo
        } else if (d + w == dist[v]) { // Agar same distance se pahunch rahe ho toh ways increase karo
          ways[v] = (ways[v] + ways[u]) % MOD;
        }
      }
    }

    return ways[dst]; // Destination node tak pahunchne ke tareeke return karo
  }

  int countPaths(int n, vector<vector<int>>& roads) {
    unordered_map<int, list<pair<int, int>>> adjList;

    for (const vector<int>& road : roads) {
      int u = road[0], v = road[1], w = road[2];
      adjList[u].push_back({v, w}); // Dono directions me edge add karo
      adjList[v].push_back({u, w});
    }

    return dijkstra(adjList, n, 0, n - 1); // Dijkstra algorithm call karo
  }
};
