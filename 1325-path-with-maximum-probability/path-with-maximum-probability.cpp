class Solution {
public:
    double bfsMaxProbability(int n, unordered_map<int, list<pair<int, double>>>& adjList, 
                             int start, int end) {
        queue<pair<int, double>> q;  // BFS ke liye queue (node, probability)
        vector<double> probToReach(n, 0.0);  // Har node tak pahunchne ki maximum probability track karne ke liye

        q.emplace(start, 1.0);  // Start node ko probability 1.0 ke saath queue me daal do
        probToReach[start] = 1.0;

        while (!q.empty()) {
            auto [u, prob] = q.front();  // Queue se front element nikalo
            q.pop();

            // Current node ke saare neighbors par traverse karo
            for (auto [nextNode, edgeProb] : adjList[u]) {
                double newProb = prob * edgeProb;  // Nayi probability calculate karo

                // Agar naye raste se probability zyada hai to update karo
                if (newProb > probToReach[nextNode]) {
                    probToReach[nextNode] = newProb;
                    q.emplace(nextNode, newProb);  // Queue me naye probability ke saath daalo
                }
            }
        }

        return probToReach[end];  // Agar end node tak pahunch sakte ho to uski probability return karo
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, 
                          int start, int end) {
        unordered_map<int, list<pair<int, double>>> adjList;  // Graph ko adjacency list ke form me store karo

        // Graph construct karo (undirected graph)
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adjList[u].emplace_back(v, prob);
            adjList[v].emplace_back(u, prob);
        }

        // BFS se maximum probability find karo
        return bfsMaxProbability(n, adjList, start, end);
    }
};
