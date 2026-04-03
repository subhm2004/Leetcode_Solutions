using P = pair<int, int>;
class Solution {
public:
    vector<int> walls;
    vector<P> robot_dist; // {pos, dist}
    vector<P> range;

    vector<vector<int>> dp;

    int count_walls_in_range(int l, int r) {
        int left = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
        int right = upper_bound(walls.begin(), walls.end(), r) - walls.begin();
        return right - left;
    }

    int solve(int i, int prev_fire_dir) {

        // base case
        if (i == robot_dist.size())
            return 0;

        if(dp[i][prev_fire_dir] != -1) return dp[i][prev_fire_dir];

        int left_start = range[i].first;

        // agar previous robot ne right fire kiya tha
        if (prev_fire_dir == 1 && i > 0) {
            left_start = max(left_start, range[i - 1].second + 1);
        }

        // left me fire kiya hai
        int left_me_fire =
            count_walls_in_range(left_start, robot_dist[i].first) +
            solve(i + 1, 0);

        // right me fire kiya hai
        int right_me_fire =
            count_walls_in_range(robot_dist[i].first, range[i].second) +
            solve(i + 1, 1);

        return dp[i][prev_fire_dir] = max(left_me_fire, right_me_fire);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& wallsInput) {

        int n = robots.size();

        // copy walls
        walls = wallsInput;

        // resize vectors
        robot_dist.resize(n);
        range.resize(n);

        // fill robot_dist
        for (int i = 0; i < n; i++) {
            robot_dist[i] = {robots[i], distance[i]};
        }

        sort(robot_dist.begin(), robot_dist.end());
        sort(walls.begin(), walls.end());

        // precompute range for each robot
        for (int i = 0; i < n; i++) {
            int pos = robot_dist[i].first;
            int d = robot_dist[i].second;

            int left_limit = (i == 0) ? 1 : robot_dist[i - 1].first + 1;
            int right_limit = (i == n - 1) ? 1e9 : robot_dist[i + 1].first - 1;

            int L = max(pos - d, left_limit);
            int R = min(pos + d, right_limit);

            range[i] = {L, R};
        }

        dp.assign(n + 1, vector<int>(2, -1));
        return solve(0, 0);
    }
};