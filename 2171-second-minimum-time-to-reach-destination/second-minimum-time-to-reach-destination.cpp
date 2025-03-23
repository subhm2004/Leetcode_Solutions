class Solution {
public:
    int dijkstraSecondMinimum(int n, unordered_map<int, list<int>>& adjList,
                              int time, int change) {
        vector<vector<int>> minTime(n + 1, vector<int>(2, INT_MAX)); 
        // Har node ke liye 2 minimum times store karenge

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
        // Min-heap (time, node)

        // BFS start karo node 1 se
        pq.emplace(0, 1);
        minTime[1][0] = 0;

        while (!pq.empty()) {
            auto [prevTime, node] = pq.top();
            pq.pop();

            // Signal red hai ya green, usko handle karna hai
            int waitTime = (prevTime / change) % 2 == 0 ? 0 : change - (prevTime % change);
            int newTime = prevTime + waitTime + time; // Naya time calculate karo

            for (int neighbor : adjList[node]) {
                if (newTime < minTime[neighbor][0]) {
                    // Pehli baar fastest time reach ho raha hai
                    minTime[neighbor][0] = newTime;
                    pq.emplace(newTime, neighbor);
                } else if (newTime > minTime[neighbor][0] && newTime < minTime[neighbor][1]) {
                    // Doosri baar minimum time reach ho raha hai
                    minTime[neighbor][1] = newTime;
                    if (neighbor == n) return newTime; 
                    // Agar destination ka second minimum time mil gaya, toh return kar do
                    pq.emplace(newTime, neighbor);
                }
            }
        }

        return -1; // Kabhi yahan nahi aana chahiye
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, list<int>> adjList; 
        // Graph ko adjacency list se represent kar rahe hain

        // Graph banana adjacency list ke saath
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        return dijkstraSecondMinimum(n, adjList, time, change);
    }
};
