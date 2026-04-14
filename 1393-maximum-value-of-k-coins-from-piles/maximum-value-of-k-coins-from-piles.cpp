class Solution {
public:

    vector<vector<int>> piles;
    vector<vector<int>> dp;

    int solve(int i, int k) {

        // Exactly k coins le liye
        if (k == 0)
            return 0;

        // Piles khatam but coins abhi bhi lene baaki
        if (i == piles.size() && k > 0) 
            return -1e9;

        if (dp[i][k] != -1)
            return dp[i][k];

        // Current pile skip
        int ans = solve(i + 1, k);

        int sum = 0;

        // Current pile se 1 to k coins lo
        for (int take = 1; take <= min((int)piles[i].size(), k); take++) {

            sum += piles[i][take - 1];

            ans = max( ans, sum + solve(i + 1, k - take));
        }

        return dp[i][k] = ans;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        this->piles = piles;

        int n = piles.size();

        dp.assign(n + 1, vector<int>(k + 1, -1));

        return solve(0, k);
    }
};