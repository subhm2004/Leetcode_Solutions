class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Step 1: XOR of all elements
        int currXOR = 0;
        for (int num : nums) {
            currXOR ^= num;
        }

        // Step 2: Calculate number of differing bits
        int diff = currXOR ^ k;

        // Step 3: Count set bits using builtin
        return __builtin_popcount(diff);
    }
};