class kadan {
public:
    int maxSubarraySum(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0) sum = 0;
        }
        return maxi;
    }

    int min_Subarray_Sum(vector<int>& nums) {
        int mini = INT_MAX;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mini = min(mini, sum);
            if (sum > 0) sum = 0;
        }
        return mini;
    }
};

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        kadan kadaneSolver;

        int maxSum = kadaneSolver.maxSubarraySum(nums);
        int minSum = kadaneSolver.min_Subarray_Sum(nums);

        return max(maxSum, abs(minSum));
    }
};
