// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         long long ans = 0;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     long long value = (nums[i] - nums[j]) * 1LL * nums[k];
//                     ans = max(ans, value);
//                 }
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = INT_MIN;     // Final answer: sabse bada (nums[i] - nums[j]) * nums[k]
        long long max_so_far = 0;     // Ab tak ka sabse bada nums[i], jiske liye i < j
        long long max_diff = 0;      // Ab tak ka sabse bada nums[i] - nums[j]

        for (int k = 0; k < nums.size(); k++) {
            // Step 1: Check karo ki agar current nums[k] ko 3rd number banayein (i < j < k)
            // toh ab tak ka best (nums[i] - nums[j]) * nums[k] kya banega
            maxi = max(maxi, max_diff * nums[k]);

            // Step 2: Update karo max_diff
            // Yaani ab tak ka sabse bada nums[i] - nums[j], jahan j < k
            max_diff = max(max_diff, max_so_far - nums[k]);

            // Step 3: Update karo max_so_far (nums[i])
            // Taaki future me use kar sake jab j < k hoga
            max_so_far = max(max_so_far, 1LL * nums[k]);
        }

        return maxi;
    }
};
