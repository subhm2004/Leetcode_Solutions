// We process pairs (i, n-1-i) together
// State: (color of left house in previous pair, color of right house in previous pair)
// For each pair, we need:
        // - left color != right color (equidistant constraint)
        // - left color != prev left color (adjacent constraint)
        // - right color != prev right color (adjacent constraint)
using ll = long long;
class Solution {
public:
    const ll INF = 1e18;

    ll dp[100005][4][4]; // dp[idx][prevL][prevR]
    int n;
    vector<vector<int>> cost;

    // idx = current pair index
    // prevL = previous left color
    // prevR = previous right color
    ll solve(int idx, int prevL, int prevR) {

        // sare pair processed ho gye hai
        if (idx == n / 2)
            return 0;

        if (dp[idx][prevL][prevR] != -1)
            return dp[idx][prevL][prevR];

        ll ans = INF;

        int L = idx;
        int R = n - 1 - idx;

        // try krte h sare color for left house
        for (int c1 = 1; c1 <= 3; c1++) {

            // adjacent condition (left side)
            if (c1 == prevL)
                continue;

            // try krte h sare color for right house
            for (int c2 = 1; c2 <= 3; c2++) {

                // adjacent condition (right side)
                if (c2 == prevR)
                    continue;

                // equidistant condition (same color nhi hona chahiye)
                if (c1 == c2)
                    continue;

                ll curr_cost =
                    cost[L][c1 - 1] + cost[R][c2 - 1] + solve(idx + 1, c1, c2);

                ans = min(ans, curr_cost);
            }
        }

        return dp[idx][prevL][prevR] = ans;
    }

    long long minCost(int n, vector<vector<int>>& cost) {

        this->n = n;
        this->cost = cost;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0);
    }
};