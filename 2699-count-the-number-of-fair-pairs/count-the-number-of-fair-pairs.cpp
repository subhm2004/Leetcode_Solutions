// typedef long long ll;
// class Solution {
// public:
//     ll countFairPairs(vector<int>& nums, int lower, int upper) {
//         ll count = 0;
//         int n = nums.size();

//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int sum = nums[i] + nums[j];
//                 if (sum >= lower && sum <= upper) {
//                     ++count;
//                 }
//             }
//         }

//         return count;
//     }
// };


typedef long long ll;

class Solution {
public:
    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        ll count = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int left = lower - nums[i];
            int right = upper - nums[i];

            // j > i only, so we search in nums[i+1 ... n-1]
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), left);
            auto high = upper_bound(nums.begin() + i + 1, nums.end(), right);

            count += high - low;
        }

        return count;
    }
};

