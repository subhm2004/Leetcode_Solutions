class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];

        long long total_sum = prefix_sum[n];

        vector<long long> suffix_product(n + 1, 1);
        for (int i = n - 1; i >= 0; i--) {
            if (suffix_product[i + 1] > total_sum / nums[i] + 1)
                suffix_product[i] = total_sum + 1;
            else
                suffix_product[i] = suffix_product[i + 1] * nums[i];
        }

        for (int i = 0; i < n; i++) {
            long long left_sum = prefix_sum[i];
            long long right_product = suffix_product[i + 1];

            if (left_sum == right_product)
                return i;
        }

        return -1;
    }
};