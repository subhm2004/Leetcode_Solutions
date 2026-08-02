class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long g = gcd(nums[i], nums[j]);
                long long strength = (1LL * nums[i] / g) * (1LL * nums[j] / g);
                ans = max(ans, strength);
            }
        }

        return ans;
    }
};