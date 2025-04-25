class kadan {
public:
    int maxSubarraySum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0) sum = 0;
        }

        return maxi;
    }
};

class Solution : public kadan {
public:
    int maxSubArray(vector<int>& nums) {
        // Directly calling inherited method
        return maxSubarraySum(nums);
    }
};
