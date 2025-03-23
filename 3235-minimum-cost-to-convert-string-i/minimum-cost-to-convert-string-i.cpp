// typedef long long ll;         // Dijkstra algo
// class Solution {
//  public:
//    ll dijkstra(int start, int end, unordered_map<int, list<pair<int, int>>>& adjList) {
//     vector<ll> dist(26, LLONG_MAX);
//     priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

//     dist[start] = 0;
//     pq.emplace(0, start);

//     while (!pq.empty()) {
//       auto [cost, node] = pq.top();
//       pq.pop();

//       if (node == end)
//         return cost;

//       if (cost > dist[node]) continue;

//       for (auto [nbr, edgeCost] : adjList[node]) {
//         if (dist[node] + edgeCost < dist[nbr]) {
//           dist[nbr] = dist[node] + edgeCost;
//           pq.emplace(dist[nbr], nbr);
//         }
//       }
//     }

//     return LLONG_MAX; // If no path exists
//   }

//   ll minimumCost(string source, string target, vector<char>& original,
//                  vector<char>& changed, vector<int>& cost) {
//     ll ans = 0;
//     unordered_map<int, list<pair<int, int>>> adjList; // adjacency list

//     // Build adjacency list for the graph
//     for (int i = 0; i < cost.size(); ++i) {
//       int u = original[i] - 'a';
//       int v = changed[i] - 'a';
//       adjList[u].push_back({v, cost[i]});  // u -> v with cost[i]
//     }

//     for (int i = 0; i < source.length(); ++i) {
//       if (source[i] == target[i])
//         continue;

//       int start = source[i] - 'a';
//       int end = target[i] - 'a';
//       ll minCost = dijkstra(start, end, adjList);

//       if (minCost == LLONG_MAX)
//         return -1;
//       ans += minCost;
//     }

//     return ans;
//   }
// };
typedef long long ll;
class Solution {
 public:
  ll minimumCost(string source, string target, vector<char>& original,
                 vector<char>& changed, vector<int>& cost) {
    vector<vector<ll>> dist(26, vector<ll>(26, LLONG_MAX));

    // Initialize self-transformation costs
    for (int i = 0; i < 26; ++i)
      dist[i][i] = 0;

    // Build the graph
    for (int i = 0; i < cost.size(); ++i) {
      int u = original[i] - 'a';
      int v = changed[i] - 'a';
      dist[u][v] = min(dist[u][v], (ll)cost[i]);  // Take min cost if multiple edges exist
    }

    // Floyd-Warshall Algorithm: Compute shortest paths for all pairs
    for (int k = 0; k < 26; ++k)
      for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
          if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // Compute total cost for the transformation
    ll ans = 0;
    for (int i = 0; i < source.length(); ++i) {
      if (source[i] == target[i])
        continue;

      int start = source[i] - 'a';
      int end = target[i] - 'a';
      ll minCost = dist[start][end];

      if (minCost == LLONG_MAX) return -1;  // No valid transformation
      ans += minCost;
    }

    return ans;
  }
};
