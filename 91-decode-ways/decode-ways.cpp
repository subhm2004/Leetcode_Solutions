class Solution {
public:
    int solveRE(int i, string& s) {
        if (i == s.size())
            return 1; // Base case: reached end, 1 valid way
        if (s[i] == '0')
            return 0; // '0' can't be decoded

        int ways = solveRE(i + 1, s); // Single digit decoding

        if (i + 1 < s.size() &&
            (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            ways += solveRE(i + 2, s); // Two-digit decoding if valid

        return ways;
    }

    int solveME(int i, string& s, vector<int>& dp) {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int ways = solveME(i + 1, s, dp);

        if (i + 1 < s.size() &&
            (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            ways += solveME(i + 2, s, dp);

        return dp[i] = ways;
    }

    int numDecodings(string s) {
        // return solveRE(0, s);
        vector<int> dp(s.size(), -1);
        return solveME(0, s, dp);
    }
};
