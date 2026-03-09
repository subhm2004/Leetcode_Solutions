class Solution {
public:
    int max_Subarray_Sum(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, sum);

            if (sum < 0)
                sum = 0;
        }

        return maxi;
    }

    int min_Subarray_Sum(vector<int>& nums) {
        int mini = INT_MAX;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mini = min(mini, sum);

            if (sum > 0)
                sum = 0;
        }

        return mini;
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int max_normal = max_Subarray_Sum(nums);

        // agar sare elements negative hai to 
        if (max_normal < 0)
            return max_normal;

        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        int min_sub = min_Subarray_Sum(nums);

        int max_circular = total_sum - min_sub;

        return max(max_normal, max_circular);
    }
};