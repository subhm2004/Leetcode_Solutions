class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;   // total sum of array
        long long F = 0;     // F(0)

        // Step 1: calculate sum and F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += 1LL * i * nums[i];
        }

        long long ans = F;

        // Step 2: use formula to get next F
        for (int k = 1; k < n; k++) {
            F = F + sum - 1LL * n * nums[n - k];
            ans = max(ans, F);
        }

        return ans;
    }
};