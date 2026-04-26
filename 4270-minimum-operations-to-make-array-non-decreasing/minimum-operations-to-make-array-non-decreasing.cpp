class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                ans += (long long)(nums[i] - nums[i + 1]);
            }
        }
        
        return ans;
    }
};