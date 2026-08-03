class Solution {
public:
    int dp[50005];

    int solveME(vector<int>& A, int i) {

        if (i >= A.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MIN;
        int total = 0;

        for (int x = 1; x <= 3; x++) {

            if (i + x > A.size())
                break;

            total += A[i + x - 1];

            ans = max(ans, total - solveME(A, i + x));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        memset(dp, -1, sizeof(dp));

        int ans = solveME(stoneValue, 0);

        if (ans > 0)
            return "Alice";
        if (ans < 0)
            return "Bob";
        return "Tie";
    }
};