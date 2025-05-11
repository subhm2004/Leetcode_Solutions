class Solution {
public:
    using ll = long long;
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

    // Calculate the score for a cycle-like structure (Ring)
    ll calculate_Ring_Score(int component_length, ll max_Value) {
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
            result += values[k] * values[(k + 1) % component_length]; // Calculate score for the cycle
        }
        return result;
    }

    // Calculate the score for a chain-like structure (Alkane)
    ll calculate_Alkane_Score(int component_length, ll max_Value) {
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
            result += values[k] * values[k + 1]; // Calculate score for the chain
        }
        return result;
    }

    // Main function to calculate the maximum score
    long long maxScore(int n, vector<vector<int>>& edges) {
        // Building the adjacency list (graph)
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].emplace_back(v, 1); // Adding a dummy weight for the edge
            adjList[v].emplace_back(u, 1); // Adding the reverse edge (undirected graph)
        }

        vector<int> cycle_Components, chain_Components;

        // For each unvisited node, check if it's part of a cycle or chain
        for (auto& [node, _] : adjList) {
            if (!visited[node]) {
                component_Size = 0; // Reset component size

                // Using DFS to check for cycles and count component size
                if (detect_Cycle_DFS(node, -1)) {
                    cycle_Components.push_back(component_Size); // It's a cycle
                } else {
                    chain_Components.push_back(component_Size); // It's a chain
                }
            }
        }

        // Sort the cycle and chain components in descending order for max scoring
        sort(cycle_Components.rbegin(), cycle_Components.rend());
        sort(chain_Components.rbegin(), chain_Components.rend());

        ll total_Score = 0;
        ll max_Value = n;

        // Calculate score for cycles (ring-like structures)
        for (int length : cycle_Components) {
            total_Score += calculate_Ring_Score(length, max_Value);
            max_Value -= length;
        }

        // Calculate score for chains (alkane-like structures)
        for (int length : chain_Components) {
            total_Score += calculate_Alkane_Score(length, max_Value);
            max_Value -= length;
        }

        return total_Score; // Final score
    }
};
