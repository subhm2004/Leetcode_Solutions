class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end()); 
        int ans = INT_MAX;

        // Step 2: Sliding Window approach
        for (int i = 0; i + k - 1 < nums.size(); i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;
    }
};
