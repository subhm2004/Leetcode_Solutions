class Solution {
public:
    int hamming_Distance(int x, int y) { return __builtin_popcount(x ^ y); }

    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                sum += hamming_Distance(nums[i], nums[j]);

        return sum;
    }
};