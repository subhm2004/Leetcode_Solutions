typedef long long ll;
class Solution {
public:
    unordered_map<int, list<pair<int, int>>> adjList; // Graph representation with adjacency list
    unordered_map<int, bool> visited; // To track visited nodes
    int component_Size = 0; // To track size of the component

    // Detect cycle using DFS (Depth First Search)
    bool detect_Cycle_DFS(int currentNode, int parentNode) {
        visited[currentNode] = true;
        component_Size++; // Counting the nodes in the current component

        for (auto& [neighbor, _] : adjList[currentNode]) {
            if (!visited[neighbor]) {
                if (detect_Cycle_DFS(neighbor, currentNode))
                    return true; // Cycle detected
            } else if (neighbor != parentNode) {
                return true; // Cycle detected
            }
        }
        return false; // No cycle found
    }

    // Calculate the score for a cycle-like structure
    ll calculate_Cycle_Score(int component_length, ll max_Value) {
        vector<ll> values(component_length);
        int i = 0, j = component_length - 1;

        while (i <= j) {
            if (i == j) values[i] = max_Value;
            else {
                values[i] = max_Value;
                values[j] = max_Value - 1;
                max_Value -= 2;
            }
            i++; j--;
        }

        ll result = 0;
        for (int k = 0; k < component_length; ++k) {
            result += values[k] * values[(k + 1) % component_length]; // Score for the cycle
        }
        return result;
    }

    // Calculate the score for a non-cycle structure
    ll calculate_NonCycle_Score(int component_length, ll max_Value) {
        vector<ll> values(component_length);
        ll minValue = max_Value - component_length + 1;
        int i = 0, j = component_length - 1;

        while (i <= j) {
            if (i == j) values[i] = minValue;
            else {
                values[i] = minValue;
                values[j] = minValue + 1;
                minValue += 2;
            }
            i++; j--;
        }

        ll result = 0;
        for (int k = 0; k < component_length - 1; ++k) {
            result += values[k] * values[k + 1]; // Score for the chain
        }
        return result;
    }

    // Main function to calculate the maximum score
    long long maxScore(int n, vector<vector<int>>& edges) {
        // Build the adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].emplace_back(v, 1); // Dummy weight
            adjList[v].emplace_back(u, 1);
        }

        vector<int> cycle_Components, nonCycle_Components;

        // Identify components
        for (auto& [node, _] : adjList) {
            if (!visited[node]) {
                component_Size = 0;

                if (detect_Cycle_DFS(node, -1)) {
                    cycle_Components.push_back(component_Size); // It's a cycle
                } else {
                    nonCycle_Components.push_back(component_Size); // Not a cycle
                }
            }
        }

        sort(cycle_Components.rbegin(), cycle_Components.rend());
        sort(nonCycle_Components.rbegin(), nonCycle_Components.rend());

        ll total_Score = 0;
        ll max_Value = n;

        // Compute cycle scores
        for (int length : cycle_Components) {
            total_Score += calculate_Cycle_Score(length, max_Value);
            max_Value -= length;
        }

        // Compute non-cycle scores
        for (int length : nonCycle_Components) {
            total_Score += calculate_NonCycle_Score(length, max_Value);
            max_Value -= length;
        }

        return total_Score;
    }
};
