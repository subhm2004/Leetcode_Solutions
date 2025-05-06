class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        
        // First pass: encode both old and new values
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] + (nums[nums[i]] % n) * n;
        }

        // Second pass: extract the new values
        for (int i = 0; i < n; ++i) {
            nums[i] /= n;
        }

        return nums;
    }
};
