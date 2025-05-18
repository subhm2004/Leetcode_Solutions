class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<int>> adjList;
        unordered_map<int, int> degree;

        // Step 1: Build adjacency list and degree map
        for (auto& road : roads) {
            int u = road[0], v = road[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Step 2: Create list of all cities
        vector<int> cities(n);
        for (int i = 0; i < n; ++i) cities[i] = i;

        // Step 3: Sort cities by degree (ascending)
        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] < degree[b];
        });

        // Step 4: Assign values using vector
        vector<int> value(n); // value[i] = value assigned to city i
        for (int i = 0; i < n; ++i) {
            value[cities[i]] = i + 1;
        }

        // Step 5: Calculate total importance
        long long total_Importance = 0;
        for (auto& road : roads) {
            int u = road[0], v = road[1];
            total_Importance += value[u] + value[v];
        }

        return total_Importance;
    }
};
