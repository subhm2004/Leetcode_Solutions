class Solution {
public:
    pair<long long, int> getSumAndZeros(const vector<int>& nums) {
        long long sum = 0;
        int zeros = 0;
        for (int num : nums) {
            sum += num;
            if (num == 0) zeros++;
        }
        return {sum, zeros};
    }

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        auto [sum1, zero1] = getSumAndZeros(nums1);
        auto [sum2, zero2] = getSumAndZeros(nums2);

        if (zero1 == 0 && sum1 < sum2 + zero2) return -1;
        if (zero2 == 0 && sum2 < sum1 + zero1) return -1;

        return max(sum1 + zero1, sum2 + zero2);
    }
};
