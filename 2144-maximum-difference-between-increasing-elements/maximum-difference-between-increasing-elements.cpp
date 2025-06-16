// class Solution { // BRUTE FORCE 
// public:
//     int maximumDifference(vector<int>& nums) {
//         int max_diff = INT_MIN;
//         int n = nums.size();

//         for (int i = 0; i < n ; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 if (nums[j] > nums[i]) {
//                     max_diff = max(max_diff, nums[j] - nums[i]);
//                 }
//             }
//         }

//         return max_diff == INT_MIN ? -1 : max_diff;
//     }
// };

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_val = nums[0];
        int max_diff = -1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > min_val) {
                max_diff = max(max_diff, nums[i] - min_val);
            } else {
                min_val = nums[i];
            }
        }

        return max_diff;
    }
};
