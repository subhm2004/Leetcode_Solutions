// class Solution {
// public:
//     string s;
//     int n, minJ, maxJ;
//     int dp[100005]; // -1 = unvisited, 0 = false, 1 = true

//     bool solve(int i) {

//         // last index reached
//         if (i == n - 1)
//             return true;

//         if (dp[i] != -1)
//             return dp[i];

//         for (int j = i + minJ; j <= min(n - 1, i + maxJ); j++) {
//             if (s[j] == '0') {
//                 if (solve(j) == true)
//                     return dp[i] = 1;
//             }
//         }

//         return dp[i] = 0;
//     }

//     bool canReach(string s, int minJump, int maxJump) {
//         this->s = s;
//         n = s.size();
//         minJ = minJump;
//         maxJ = maxJump;

//         memset(dp, -1, sizeof(dp));

//         return solve(0);
//     }
// };

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int> dp(n, 0);
        dp[0] = 1;
        int count = 0;
        for(int j = 1; j <= n-1; j++) {
            if(j - minJump >= 0) {
                count += dp[j - minJump];
            }
            if(j - maxJump - 1 >= 0) {
                count -= dp[j - maxJump - 1];
            }
            if(count > 0 && s[j] == '0') {
                dp[j] = 1;
            }
        }
        return dp[n-1] > 0;
    }
};