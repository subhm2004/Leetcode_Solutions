class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[201][201][2];  
    // flag represents krta hai kya last character 0 tha
    int solveME(int one_left, int zero_left, bool flag, int limit) {
        if (one_left == 0 && zero_left == 0) return 1;

        if (dp[one_left][zero_left][flag] != -1) {
            return dp[one_left][zero_left][flag];
        }

        int ans = 0;
        if (flag == true) { 
            // previous character 0 tha ab 1 ko pick kro 
            for (int i = 1; i <= min(one_left, limit); i++) {
                ans = (ans + solveME(one_left - i, zero_left, false, limit)) % MOD;
            }
        } else { 
            // previous character 1 tha ab 0 ko pick kro
            for (int i = 1; i <= min(zero_left, limit); i++) {
                ans = (ans + solveME(one_left, zero_left - i, true, limit)) % MOD;
            }
        }

       return dp[one_left][zero_left][flag] = ans;  
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        
        int start_1 = solveME(one, zero, true, limit);  // starting with 1
        int start_0 = solveME(one, zero, false, limit); // starting with 0

        return (start_1 + start_0 ) % MOD;
    }
};
