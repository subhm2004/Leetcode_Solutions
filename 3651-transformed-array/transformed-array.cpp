class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans[i] = 0;
            } else {
                int new_idx = (i + nums[i]) % n;
                if (new_idx < 0) new_idx += n; 
                ans[i] = nums[new_idx];
            }
        }
        return ans;
    }
};
