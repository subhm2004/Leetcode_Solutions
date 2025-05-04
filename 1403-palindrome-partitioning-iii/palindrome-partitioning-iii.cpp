class Solution {
public:
    int calculateCost(string& s, int left, int right) {
        int changes = 0;
        while (left < right) {
            if (s[left++] != s[right--])
                ++changes;
        }
        return changes;
    }

    int solveRE(int i, int k, string& s) {
        int n = s.size();
        if (i == n)
            return (k == 0) ? 0 : INT_MAX;
        if (k == 0)
            return INT_MAX;

        int minChanges = INT_MAX;

        for (int j = i; j < n; ++j) {
            int cost = calculateCost(s, i, j);
            int nextPartition = solveRE(j + 1, k - 1, s);
            if (nextPartition != INT_MAX) {
                minChanges = min(minChanges, cost + nextPartition);
            }
        }

        return minChanges;
    }

    int solveME(int i, int k, string& s, vector<vector<int>>& dp) {
        int n = s.size();
        if (i == n)
            return (k == 0) ? 0 : INT_MAX;
        if (k == 0)
            return INT_MAX;

        if (dp[i][k] != -1)
            return dp[i][k];

        int minChanges = INT_MAX;

        for (int j = i; j < n; ++j) {
            int cost = calculateCost(s, i, j);
            int nextPartition = solveME(j + 1, k - 1, s, dp);
            if (nextPartition != INT_MAX) {
                minChanges = min(minChanges, cost + nextPartition);
            }
        }

        return dp[i][k] = minChanges;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solveME(0, k, s, dp);  
    }
};
