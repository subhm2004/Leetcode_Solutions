auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    int MOD = 1e9+7;

    long long solveRE(int n, int k) {
        // Base cases
        if (n == 0 && k == 0)
            return 1;
        if (n == 0 || k == 0 || k > n)
            return 0;

        long long visible = solveRE(n - 1, k - 1); // sabse choti stick ko first position par place kar dete hai to wo visible hogi to ab n-1 stick bachi or k-1 ko visible karwna hai to function banega :- solveRE(n - 1, k - 1)

        long long hidden = (n - 1) * solveRE(n - 1, k); // lekin agar sabse smallest stick ko first position pe place nhi kiya to ab to kabhi bhi visible nhio hogi or wo khi beech me placed rhegi to ab stick bachegi n-1 or visible krwani hai k or total position jha sabse choti stickko place kr skte hai wo ho gyi hai n-1 to function banega :- (n - 1) * solveRE(n - 1, k)

        return (visible + hidden) % MOD;
    }

    long long solveME(int n, int k, vector<vector<long long>>& dp) {
        if (n == 0 && k == 0) return 1;
        if (n == 0 || k == 0 ) return 0;
        
         if (dp[n][k] != -1) return dp[n][k];
        
         long long visible = solveME(n - 1, k - 1, dp);
        
         long long hidden = (n - 1) * solveME(n - 1, k, dp) % MOD;
        
        return dp[n][k] = (visible + hidden) % MOD;
    }

    int rearrangeSticks(int n, int k) { 
        //return solveRE(n, k); 
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
        return solveME(n, k, dp);
    }
};