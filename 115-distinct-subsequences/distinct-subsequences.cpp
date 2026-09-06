class Solution {
public:

    int dp[1001][1001];

    int solveME(string& s, string& t, int i, int j) {

        // Agar t pura match ho gaya to ek valid subsequence mil gayi
        if (j == t.size())
            return 1;

        // Agar s khatam ho gaya lekin t abhi baaki hai to match possible nahi hai
        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        // Agar current characters match karte hain
        if (s[i] == t[j]) {

            // Current character ko choose kar rahe hain
            ans += solveME(s, t, i + 1, j + 1);
        }

        // Current character ko skip kar rahe hain
        ans += solveME(s, t, i + 1, j);

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {

        memset(dp, -1, sizeof(dp));

        return solveME(s, t, 0, 0);
    }
};