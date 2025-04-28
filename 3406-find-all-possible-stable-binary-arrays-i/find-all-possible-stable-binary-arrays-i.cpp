class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[201][201][2];  

    int solveRE(int one, int zero, bool flag, int limit) {
        if (one == 0 && zero == 0) return 1;

        int ans = 0;
        if (flag) { // Previous was 0, now need to pick 1's
            for (int i = 1; i <= min(one, limit); i++) {
                ans = (ans + solveRE(one - i, zero, false, limit)) % MOD;
            }
        } else { // Previous was 1, now need to pick 0's
            for (int i = 1; i <= min(zero, limit); i++) {
                ans = (ans + solveRE(one, zero - i, true, limit)) % MOD;
            }
        }

        return ans;
    }

    int solveME(int one, int zero, bool flag, int limit) {
        if (one == 0 && zero == 0) return 1;

        // If the value has already been computed, return it
        if (dp[one][zero][flag] != -1) {
            return dp[one][zero][flag];
        }

        int ans = 0;
        if (flag) { // Previous was 0, now need to pick 1's
            for (int i = 1; i <= min(one, limit); i++) {
                ans = (ans + solveME(one - i, zero, false, limit)) % MOD;
            }
        } else { // Previous was 1, now need to pick 0's
            for (int i = 1; i <= min(zero, limit); i++) {
                ans = (ans + solveME(one, zero - i, true, limit)) % MOD;
            }
        }

       return dp[one][zero][flag] = ans;  
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        // Initialize the dp array with -1 
        memset(dp, -1, sizeof(dp));
        
        // Solving using the ME (memoization) approach
        int startWithOne = solveME(one, zero, true, limit);  // Assume starting with 1
        int startWithZero= solveME(one, zero, false, limit); // Assume starting with 0

        return (startWithOne + startWithZero) % MOD;
    }
};
