class Solution {
public:
    long long fuel = 0;  
    int seats;

    long long dfs(int node, int parent, unordered_map<int, list<int>>& adjList) {
        long long reps = 1;
        for (auto& nbr : adjList[node]) {
            if (nbr == parent) continue;
            reps += dfs(nbr, node, adjList);
        }
        if (node != 0) {
            long long cars = (reps + seats - 1) / seats;
            fuel += cars;
        }
        return reps;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        this->seats = seats;
        unordered_map<int, list<int>> adjList;
        for (auto& r : roads) {
            adjList[r[0]].push_back(r[1]);
            adjList[r[1]].push_back(r[0]);
        }
        dfs(0, -1, adjList);
        return fuel;
    }
};
