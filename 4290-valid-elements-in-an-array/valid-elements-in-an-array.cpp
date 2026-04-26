class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {nums[0]};
        
        vector<int> leftMax(n), rightMax(n);
        
        // leftMax[i] = maximum element from 0 to i-1
        leftMax[0] = -1;
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }
        
        // rightMax[i] = maximum element from i+1 to n-1
        rightMax[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i + 1]);
        }
        
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1 || nums[i] > leftMax[i] || nums[i] > rightMax[i]) {
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};