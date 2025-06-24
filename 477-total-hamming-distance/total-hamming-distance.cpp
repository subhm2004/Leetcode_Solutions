// class Solution {
// public:
//     int hamming_Distance(int x, int y) { return __builtin_popcount(x ^ y); }

//     int totalHammingDistance(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for (int i = 0; i < n; i++)
//             for (int j = i + 1; j < n; j++)
//                 sum += hamming_Distance(nums[i], nums[j]);

//         return sum;
//     }
// };
//-------------------------------------------------------------------------------
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int n = nums.size();

        for (int bit = 0; bit < 32; ++bit) {
            int count_ones = 0;
            for (int num : nums) {
                if (num & (1 << bit)) count_ones++;
            }
            int count_zeros = n - count_ones;
            total += count_ones * count_zeros;
        }

        return total;
    }
};
