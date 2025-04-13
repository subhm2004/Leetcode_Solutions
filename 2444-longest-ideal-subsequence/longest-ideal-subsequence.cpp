class Solution {
public:
    // Recursive approach
    int solveRE(string& s, int curr, int prev, int k) {
        if (curr >= s.size())
            return 0;

        int include = 0;
        if (prev == -1 || abs(s[curr] - s[prev]) <= k) {
            include = 1 + solveRE(s, curr + 1, curr, k);
        }

        int exclude = solveRE(s, curr + 1, prev, k);
        return max(include, exclude);
    }

    // Memoization (Top-Down DP)
    int solveME(string& s, int curr, int prev, int k, vector<vector<int>>& dp) {
        if (curr >= s.size())
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int include = 0;
        if (prev == -1 || abs(s[curr] - s[prev]) <= k) {
            include = 1 + solveME(s, curr + 1, curr, k, dp);
        }

        int exclude = solveME(s, curr + 1, prev, k, dp);
        return dp[curr][prev + 1] = max(include, exclude);
    }

    // Tabulation (Bottom-Up DP)
    int solve_BU(string& s, int k) {
        int n = s.size();
        vector<int> dp(n, 1); // dp[i] = length of ideal subsequence ending at index i
        int max_Length = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (abs(s[i] - s[j]) <= k) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_Length = max(max_Length, dp[i]);
        }

        return max_Length;
    
    }

    // Optimized Bottom-Up DP
    int solve_BU_Optmized(string& s, int k) {
        int n = s.length();
        
        vector<int> dp(26, 0);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            
            int curr    = s[i]-'a';
            int left    = max(0, curr-k);
            int right   = min(25, curr+k);

            int longest = 0;
            for(int j = left; j <= right; j++) {
                longest = max(longest, dp[j]);
            }
            
            dp[curr] = max(dp[curr], longest+1);
            ans = max(ans, dp[curr]);
        }
        
        return ans;
    }

    int longestIdealString(string s, int k) {
        //vector<vector<int>> dp(s.size(), vector<int>(s.size() + 1, -1));
        // return solveRE(s, 0, -1, k);
        // return solveME(s, 0, -1, k, dp);
        // return solve_BU(s, k);
        return solve_BU_Optmized(s,k);
    }
};
