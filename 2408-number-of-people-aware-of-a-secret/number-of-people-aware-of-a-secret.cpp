class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> dp;   

    // This returns number of people who first learn the secret on "day"
    int solveME(int day, int delay, int forget) {
        if (day == 1) return 1;
        if (day <= 0) return 0;

        if (dp[day] != -1) return dp[day];

        long long ans = 0;
        // people who can share today are those who learned it in
        // [day - forget + 1, day - delay]
        for (int prev = day - forget + 1; prev <= day - delay; prev++) {
            if (prev > 0) {
                ans = (ans + solveME(prev, delay, forget)) % MOD;
            }
        }
        return dp[day] = ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        dp.assign(n + 1, -1);   
        long long total = 0;

        // only count people who haven't forgotten by day n
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                total = (total + solveME(day, delay, forget)) % MOD;
            }
        }
        return total;
    }
};
