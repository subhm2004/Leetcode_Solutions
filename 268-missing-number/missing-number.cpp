// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int sum1 = (n * (n + 1) / 2);
//         int sum2 = accumulate(nums.begin(), nums.end(), 0);
//         return sum1 - sum2;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_all = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            xor_all ^= i ^ nums[i];
        }
        xor_all ^= n;

        return xor_all;
    }
};