class Solution {
public:
    bool maths(int x, int y, int target) {
        if (target > x + y)
            return false;
        if (target == 0)
            return true;
        return target % __gcd(x, y) == 0;
    }

        // ---------- Helper for visited check ----------
    bool is_visited(vector<pair<int, int>>& visited, pair<int, int> state) {
        for (auto& p : visited) {
            if (p.first == state.first && p.second == state.second)
                return true;
        }
        return false;
    }
        // ---------- BFS ----------
    bool BFS(int x, int y, int target) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> visited;

        q.push({0, 0});
        visited.push_back({0, 0});

        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            if (a == target || b == target || a + b == target)
                return true;

            vector<pair<int, int>> next_states = {
                {x, b},                               // Fill jug1
                {a, y},                               // Fill jug2
                {0, b},                               // Empty jug1
                {a, 0},                               // Empty jug2
                {max(0, a - (y - b)), min(y, b + a)}, // Pour jug1 -> jug2
                {min(x, a + b), max(0, b - (x - a))}  // Pour jug2 -> jug1
            };

            for (auto& state : next_states) {
                if (!is_visited(visited, state)) {
                    visited.push_back(state);
                    q.push(state);
                }
            }
        }
        return false;
    }

    // ---------- DFS ----------
    vector<pair<int, int>> visited_dfs;

    bool DFS_helper(int a, int b, int x, int y, int target) {
        if (a == target || b == target || a + b == target)
            return true;
        if (is_visited(visited_dfs, {a, b}))
            return false;

        visited_dfs.push_back({a, b});

        return DFS_helper(x, b, x, y, target) || // Fill jug1
               DFS_helper(a, y, x, y, target) || // Fill jug2
               DFS_helper(0, b, x, y, target) || // Empty jug1
               DFS_helper(a, 0, x, y, target) || // Empty jug2
               DFS_helper(max(0, a - (y - b)), min(y, b + a), x, y,
                         target) || // Pour jug1 -> jug2
               DFS_helper(min(x, a + b), max(0, b - (x - a)), x, y,
                         target); // Pour jug2 -> jug1
    }

    bool DFS(int x, int y, int target) {
        visited_dfs.clear();
        return DFS_helper(0, 0, x, y, target);
    }

    bool canMeasureWater(int x, int y, int target) {
        // return maths(x,y,target);
        // return DFS(x,y,target);
        return BFS(x,y,target);
    }
};