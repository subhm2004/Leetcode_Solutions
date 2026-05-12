// Dijkstra + Binary Search 
class Solution {
public:
    /* Check if target is reachable from source with at most k heavy edges  given a specific threshold
    */
    bool can_reach(int n, vector<vector<int>>& edges, int source, int target,
                   int k, int threshold) {

        unordered_map<int, list<pair<int, int>>> adjList;

        for (auto& e : edges) {
            adjList[e[0]].push_back({e[1], e[2]});
            adjList[e[1]].push_back({e[0], e[2]});
        }

        // Dijkstra with state (node, heavyUsed)

        // visited[node][heavyUsed] = true if already processed
        vector<vector<bool>> visited(n, vector<bool>(k + 2, false));

        // Min-heap: (heavyEdgesUsed, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [heavy, node] = pq.top();
            pq.pop();

            // Skip if already visited this state
            if (visited[node][heavy])
                continue;

            visited[node][heavy] = true;

            // Reached target within budget
            if (node == target)
                return true;

            for (auto& [next, w] : adjList[node]) {

                // Determine if this edge is heavy
                int new_heavy = heavy + (w > threshold ? 1 : 0);


                // Only proceed if within budget and state not visited
                if (new_heavy <= k && !visited[next][new_heavy]) {
                    pq.push({new_heavy, next});
                }
            }
        }
        return false;
    }

    int minimumThreshold(int n, vector<vector<int>>& edges, int source,
                         int target, int k) {

        if (source == target)
            return 0;

        vector<int> weights;
        weights.push_back(0);
        for (auto& e : edges)
            weights.push_back(e[2]);

        sort(weights.begin(), weights.end());

        int low = 0;
        int high = (int)weights.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int threshold = weights[mid];

            if (can_reach(n, edges, source, target, k, threshold)) {
                ans = threshold;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};