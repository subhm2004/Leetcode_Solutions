// class Solution {          // LIS varient hai    TLE 20/40
// public:
//     int constrainedSubsetSum(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> dp(n); // dp[i] = max sum ending at i
//         int ans = nums[0];

//         for (int i = 0; i < n; ++i) {
//             dp[i] = nums[i];

//             // Look back up to k elements
//             for (int j = max(0, i - k); j < i; ++j) {
//                 dp[i] = max(dp[i], nums[i] + dp[j]);
//             }

//             ans = max(ans, dp[i]);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;       // max(dp[j]) ko maintain karne ke liye (j in [i-k, i-1])
        vector<int> dp(n);   // dp[i] = max sum of subsequence ending at index i
        int ans = nums[0];   // Final result store karne ke liye

        for (int i = 0; i < n; ++i) {
            // Step 1: dp[i] ki value initialize karo
            // dp[i] = nums[i] + max(dp[j]) where j in [i-k, i-1]
            dp[i] = nums[i];
            if (!dq.empty()) {
                dp[i] = max(dp[i], nums[i] + dp[dq.front()]);
            }

            // Step 2: Maintain deque in decreasing order of dp values
            while (!dq.empty() && dp[dq.back()] < dp[i]) {
                dq.pop_back();  // chhoti values ko hata do, kyunki wo kabhi kaam nahi aayengi
            }

            dq.push_back(i); // current index ko push karo

            // Step 3: Window se bahar wale index ko remove karo
            if (i - dq.front() >= k) {
                dq.pop_front();
            }

            // Step 4: Answer update karo
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
