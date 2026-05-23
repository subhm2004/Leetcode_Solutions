class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        
        for (int x : nums) {
            if (x == 0)
                zeros++;
        }

        int swaps = 0;

        for (int i = n - zeros; i < n ; i++) {
            if (nums[i] != 0)
                swaps++;
        }

        return swaps;

    }
};