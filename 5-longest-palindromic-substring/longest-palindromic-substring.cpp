class Solution {
public:
    int maxlen = 1, start = 0;
    
    bool solveRE(string& s, int i, int j) {
        if (i >= j) return true;
        
        if (s[i] == s[j] && solveRE(s, i + 1, j - 1)) {
            int currlen = j - i + 1;
            if (currlen > maxlen) {
                maxlen = currlen;
                start = i;
            }
            return true;
        }
        return false;
    }
    
   bool solveME(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];

        bool flag = 0;
        if (s[i] == s[j]) {
            flag = solveME(s, i + 1, j - 1, dp);
        }

        if (flag) {
            int currlen = j - i + 1;
            if (currlen > maxlen) {
                maxlen = currlen;
                start = i;
            }
        }
        return dp[i][j] = flag;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                solveME(s, i, j, dp);
            }
        }
        
        return s.substr(start, maxlen);
    }
};
