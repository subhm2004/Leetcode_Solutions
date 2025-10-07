// class Solution {
// public:
//     vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, 0);

//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = 0; j < n; j++) {
//                 if (i != j) {
//                     sum += abs(nums[i] - nums[j]);
//                 }
//             }
//             ans[i] = sum;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        vector<int> ans(n, 0);

        // Step 1: prefix sum of nums
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        // Step 2: formula 
        // ans[i] = (i * nums[i] - sum_left) + (sum_right - (n - i - 1) * nums[i])
        for (int i = 0; i < n; i++) {
            long long left_sum = (i > 0) ? prefix[i - 1] : 0;
            long long right_sum = prefix[n - 1] - prefix[i];

            long long left_part = (1LL * i * nums[i]) - left_sum;
            long long right_part = right_sum - (1LL * (n - i - 1) * nums[i]);

            ans[i] = left_part + right_part;
        }

        return ans;
    }
};
/*
Count ka formula:

Number of elements in a range [start, end] = end - start + 1

Yahan, start = i+1
      end   = n-1

Toh:
Count = (n-1) - (i+1) + 1

Simplify:
(n-1) - (i+1) + 1
= n - 1 - i - 1 + 1
= n - i - 1

Yani humara n - i - 1 hai — number of elements strictly right of index i
*/
