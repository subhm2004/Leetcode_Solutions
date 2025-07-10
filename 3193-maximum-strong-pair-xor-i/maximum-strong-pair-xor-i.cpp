// class Solution {
// public:
//     int maximumStrongPairXor(vector<int>& nums) {
//         int maxXor = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             int x = nums[i];
//             for (int j = 0; j < n; ++j) {
//                 int y = nums[j];
//                 if (max(x, y) <= 2 * min(x, y)) {
//                     maxXor = max(maxXor, x ^ y);
//                 }
//             }
//         }
//         return maxXor;
//     }
// };

/*
case 1 : x ≤ y
|x - y| = y - x
min(x, y) = x

So: y - x ≤ x
=> y ≤ 2x

case 2 : y ≤ x
|x - y| = x - y
min(x, y) = y

So: x - y ≤ y
=> x ≤ 2y

so dono ko comine krke solve hoke aata hai
=> max(x, y) ≤ 2 * min(x, y)


*/

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxXor = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n && nums[j] <= 2 * nums[i]; ++j) {
                 if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                    maxXor = max(maxXor, nums[i] ^ nums[j]);
                }
            }
        }

        return maxXor;
    }
};
