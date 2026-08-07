class Solution {
public:
    const int LIMIT = 1e4 + 5;

    int bfs(int x, int y) {
        vector<bool> visited(LIMIT, false);

        queue<pair<int, int>> q;
        q.push({x, 0});
        visited[x] = true;

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == y)
                return steps;

            // x-1
            if (curr - 1 >= 1 && !visited[curr - 1]) {
                visited[curr - 1] = true;
                q.push({curr - 1, steps + 1});
            }
            // X + 1
            if (curr + 1 < LIMIT && !visited[curr + 1]) {
                visited[curr + 1] = true;
                q.push({curr + 1, steps + 1});
            }

            if (curr % 5 == 0 && !visited[curr / 5]) {
                visited[curr / 5] = true;
                q.push({curr / 5, steps + 1});
            }

            if (curr % 11 == 0 && !visited[curr / 11]) {
                visited[curr / 11] = true;
                q.push({curr / 11, steps + 1});
            }
        }
        return -1;
    }
    int minimumOperationsToMakeEqual(int x, int y) { return bfs(x, y); }
};