class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
};
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         return nums[0];
//     }
// };

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int low = 0;
//         int high = nums.size() - 1;
//         int ans = INT_MAX;
//         while (low <= high) {
//             int mid = (high + low) >> 1;
//             if (nums[low] <= nums[mid]) {
//                 ans = min(ans, nums[low]);
//                 low = mid + 1;
//             } else {
//                 ans = min(ans, nums[mid]);
//                 high = mid - 1;
//             }
//         }
//         return ans;
//     }
// };