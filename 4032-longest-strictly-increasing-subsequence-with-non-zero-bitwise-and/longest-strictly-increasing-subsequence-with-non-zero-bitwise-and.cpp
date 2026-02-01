class Solution { // Same as LC 300
public:
    bool is_set_Bit(int i, int x) { // function to check ith bit set in x
        return (x & (1LL << i)) != 0;
    }
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;

        for (int bit = 0; bit < 31; bit++) {

            vector<int> lis;   // patience array

            for (int x : nums) {

                if (is_set_Bit(bit, x)) {   

                    auto it = lower_bound(lis.begin(), lis.end(), x);

                    if (it == lis.end())
                        lis.push_back(x);
                    else
                        *it = x;
                }
            }

            ans = max(ans, (int)lis.size());
        }

        return ans;
    }
};

// class Solution { // MLE
// public:

//     bool is_set_Bit(int i, int x) { //function to check ith bit set in x
//         return (x & (1LL << i)) != 0;
//     }

//     int solveME(vector<int>& arr, int curr, int prev,
//                 vector<vector<int>>& dp) {

//         if (curr >= arr.size())
//             return 0;

//         if (dp[curr][prev + 1] != -1)
//             return dp[curr][prev + 1];

//         int include = 0;
//         if (prev == -1 || arr[curr] > arr[prev]) {
//             include = 1 + solveME(arr, curr + 1, curr, dp);
//         }

//         int exclude = solveME(arr, curr + 1, prev, dp);

//         return dp[curr][prev + 1] = max(include, exclude);
//     }

//     int longestSubsequence(vector<int>& nums) {

//         int ans = 0;

//         for (int bit = 0; bit < 31; bit++) {

//             vector<int> arr;

//             for (int num : nums) {
//                 if (is_set_Bit(bit, num)) {
//                     arr.push_back(num);
//                 }
//             }

//             int n = arr.size();
//             if (n == 0) continue;

//             vector<vector<int>> dp(n, vector<int>(n + 1, -1));

//             ans = max(ans, solveME(arr, 0, -1, dp));
//         }

//         return ans;
//     }
// };
