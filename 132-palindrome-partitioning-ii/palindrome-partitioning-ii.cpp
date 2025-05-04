class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solveRE(int i, string& s) {
        int n = s.size();
        if (i >= n) return 0;

        int minCutsNeeded = n;

        for (int j = i; j < n; ++j) {
            if (isPalindrome(s, i, j)) {
                minCutsNeeded = min(minCutsNeeded, 1 + solveRE(j + 1, s));
            }
        }

        return minCutsNeeded;
    }

    int solveME(int i, string& s, vector<int>& dp) {
        int n = s.size();
        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];

        int minCutsNeeded = n;

        for (int j = i; j < n; ++j) {
            if (isPalindrome(s, i, j)) {
                minCutsNeeded = min(minCutsNeeded, 1 + solveME(j + 1, s, dp));
            }
        }

        return dp[i] = minCutsNeeded;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solveME(0, s, dp) - 1;
    }
};
