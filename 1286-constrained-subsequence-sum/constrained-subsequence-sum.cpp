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
        deque<int> dq;       // Isme hum dp ke indexes rakhenge decreasing order me
        vector<int> dp(n);   // dp[i] = nums[i] se end hone wale subsequence ka max sum
        int ans = nums[0];   // Final answer yahi store hoga

        for (int i = 0; i < n; ++i) {
            // Agar deque empty hai to sirf nums[i] hi consider karo
            dp[i] = nums[i];
            if (!dq.empty()) {
                // nums[i] + pichle k range me max dp value add kar rahe
                dp[i] = max(dp[i], nums[i] + dp[dq.front()]);
            }

            // Deque ko decreasing order me maintain karo
            while (!dq.empty() && dp[dq.back()] < dp[i]) {
                dq.pop_back(); // Peeche se chhoti values hatao
            }

            dq.push_back(i); // Current index ko push karo

            // Agar deque ka front window ke bahar chala gaya to hatao
            if (i - dq.front() >= k) {
                dq.pop_front();
            }

            // ab tak ka max answer update karo
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
