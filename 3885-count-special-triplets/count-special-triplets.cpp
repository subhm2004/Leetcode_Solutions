// class Solution { // TLE 947/1121
// public:
//     int specialTriplets(vector<int>& nums) {
//         int n = nums.size();
//         long long count = 0;
//         int MOD = 1e9 + 7;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 for (int k = j + 1; k < n; ++k) {
//                     if (nums[i] == 2 * nums[j] && nums[k] == 2 * nums[j]) {
//                         count = (count + 1) % MOD;
//                     }
//                 }
//             }
//         }

//         return count;
//     }
// };


// class Solution {        // TLE 1098/1121
// public:
//     int specialTriplets(vector<int>& nums) {
//         int n = nums.size();
//         long long ans = 0;
//         const int MOD = 1e9 + 7;

//         for (int j = 0; j < n; ++j) {
//             long long count_Left = 0;
//             long long count_Right = 0;

//             for (int i = 0; i < j; ++i) {
//                 if (nums[i] == 2 * nums[j]) count_Left++;
//             }

//             for (int k = j + 1; k < n; ++k) {
//                 if (nums[k] == 2 * nums[j]) count_Right++;
//             }

//             ans = (ans + (count_Left * count_Right) % MOD) % MOD;
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9 + 7;
        unordered_map<long long, int> left, right;
        for (int num : nums) right[num]++;
        
        long long ans = 0;
        for (int j = 0; j < nums.size(); ++j) {
            right[nums[j]]--; // We're at index j now
            long long x = nums[j] * 2LL;
            int count_left = left[x];
            int count_right = right[x];
            ans = (ans + 1LL * count_left * count_right) % MOD;
            left[nums[j]]++;
        }
        
        return ans;
    }
};

