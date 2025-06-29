class Solution {
public:
    //  Check if substring s[l..r] is a palindrome
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

     int solveRE(int i, string& s, int k) {
        int n = s.length();
        if (i >= n)
            return 0;

        int maxCount = solveRE(i + 1, s, k); // skip current character

        for (int j = i + k - 1; j < n; ++j) {
            if (isPalindrome(s, i, j)) {
                maxCount = max(maxCount, 1 + solveRE(j + 1, s, k));
                break; // break to ensure non-overlapping palindromes
            }
        }

        return maxCount;
    }

    int solveME(int i, string& s, int k, vector<int>& dp) {
        int n = s.length();
        if (i >= n)
            return 0;

        if (dp[i] != -1) return dp[i];

        int maxCount = solveME(i + 1, s, k, dp); // skip current character

        for (int j = i + k - 1; j < n; ++j) {
            if (isPalindrome(s, i, j)) {
                maxCount = max(maxCount, 1 + solveME(j + 1, s, k, dp));
                break; // ensure non-overlapping
            }
        }

        return dp[i] = maxCount;
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<int> dp(n, -1);  // dp[i] = max palindromes starting at index i
        return solveME(0, s, k, dp);
    }
};
