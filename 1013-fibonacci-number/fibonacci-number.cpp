// class Solution {
//  public:
//   int fib(int n) {
//     if (n < 2)
//       return n;

//     int a = 0, b = 1;

//     for (int i = 2; i <= n; ++i) {
//       int sum = a + b;
//       a = b;
//       b = sum;
//     }

//     return b;
//   }
// };

class Solution {
public:
    int solveME(int n, vector<int>& dp) {
        if (n == 1 || n == 0)
            return n;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solveME(n - 1, dp) + solveME(n - 2, dp);
    }
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        int ans = solveME(n, dp);
        return ans;
    }
};
