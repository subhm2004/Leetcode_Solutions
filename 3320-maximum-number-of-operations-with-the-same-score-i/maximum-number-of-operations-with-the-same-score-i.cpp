class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ans = 1; // At least one operation is always possible
        int sum = nums[0] + nums[1]; // Store the sum of the first pair

        // Check consecutive pairs
        for (int i = 2; i + 1 < nums.size(); i += 2) {
            if (nums[i] + nums[i + 1] != sum) {
                break;
            } // Stop if a pair's sum is different
            ans++;
        }
        return ans;
    }
};
