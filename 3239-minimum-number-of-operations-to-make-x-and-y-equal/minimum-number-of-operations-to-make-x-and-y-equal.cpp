class Solution {
public:
    const int MAX_LIMIT = 1e5;

    int bfs(int x, int y) {

        vector<bool> visited(MAX_LIMIT + 1, 0);

        queue<pair<int, int>> q;
        q.push({x, 0});
        visited[x] = true;

        while (!q.empty()) {

            auto [curr, steps] = q.front();
            q.pop();

            if (curr == y)
                return steps;

            // x - 1
            if (curr - 1 >= 1 && !visited[curr - 1]) {
                visited[curr - 1] = true;
                q.push({curr - 1, steps + 1});
            }

            // x + 1
            if (curr + 1 <= MAX_LIMIT && !visited[curr + 1]) {
                visited[curr + 1] = true;
                q.push({curr + 1, steps + 1});
            }

            // Divide by 5
            if (curr % 5 == 0 && !visited[curr / 5]) {
                visited[curr / 5] = true;
                q.push({curr / 5, steps + 1});
            }

            // Divide by 11
            if (curr % 11 == 0 && !visited[curr / 11]) {
                visited[curr / 11] = true;
                q.push({curr / 11, steps + 1});
            }
        }

        return -1;
    }

    int minimumOperationsToMakeEqual(int x, int y) {

        return bfs(x, y);
    }
};