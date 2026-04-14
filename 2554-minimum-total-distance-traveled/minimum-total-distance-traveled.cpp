class Solution {
public:
    vector<int> robot;
    vector<vector<int>> factory;
    vector<vector<vector<long long>>> dp;

    long long solve(int i, int j, int used) {

        // Sab robots assign ho gaye
        if (i == robot.size())
            return 0;

        // Factory khatam but robots bache
        if (j == factory.size())
            return 1e18;

        if (dp[i][j][used] != -1)
            return dp[i][j][used];

        long long skip_factory = solve(i, j + 1, 0);

        long long take = 1e18;

        int position = factory[j][0];
        int limit = factory[j][1];

        if (used < limit) {
            take = abs(robot[i] - position) + solve(i + 1, j, used + 1);
        }

        return dp[i][j][used] = min(skip_factory, take);
    }

    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {

        robot = r;
        factory = f;

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        dp.assign( n, vector<vector<long long>>( m, vector<long long>(n + 1, -1) ) );

        return solve(0, 0, 0);
    }
};