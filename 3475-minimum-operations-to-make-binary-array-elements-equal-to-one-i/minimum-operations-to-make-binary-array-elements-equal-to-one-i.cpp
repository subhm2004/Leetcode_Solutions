class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), operations = 0;

        for (int i = 0; i <= n - 3; ++i) {
            if (nums[i] == 0) {
                nums[i + 1] ^= 1;  // Flip next element
                nums[i + 2] ^= 1;  // Flip the element after that
                ++operations;
            }
        }

        return (nums[n - 1] == 0 || nums[n - 2] == 0) ? -1 : operations;
    }
};
