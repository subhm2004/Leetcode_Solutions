class Solution {
public:
    const int INF = 1e9;
    int dp[101][21][101];

    vector<int> houses;
    vector<vector<int>> cost;
    int m, n, target;

    int solve(int idx, int prev_color, int nbr_count) {

        if (nbr_count > target) return INF;

        if (idx == m)
            return (nbr_count == target ? 0 : INF);

        if (dp[idx][prev_color][nbr_count] != -1)
            return dp[idx][prev_color][nbr_count];

        int ans = INF;

        if (houses[idx] != 0) {

            int new_nbr_count = nbr_count + (houses[idx] != prev_color);

            ans = solve(idx + 1, houses[idx], new_nbr_count);
        }
        else {

            for (int color = 1; color <= n; color++) {

                int new_nbr_count = nbr_count + (color != prev_color);

                int curr_cost = cost[idx][color - 1] + solve(idx + 1, color, new_nbr_count);

                ans = min(ans, curr_cost);
            }
        }

        return dp[idx][prev_color][nbr_count] = ans;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        this->houses = houses;
        this->cost = cost;
        this->m = m;
        this->n = n;
        this->target = target;

        memset(dp, -1, sizeof(dp));

        int ans = solve(0, 0, 0);

        return (ans >= INF ? -1 : ans);
    }
};