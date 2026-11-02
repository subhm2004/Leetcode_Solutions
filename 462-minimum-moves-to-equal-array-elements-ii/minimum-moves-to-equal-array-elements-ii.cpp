class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Choose the median as the target value
        int median = nums[nums.size() / 2];  
        
        // Step 3: Calculate total moves needed to make all elements equal to median
        int totalMoves = 0;
        for (int num : nums) {
            totalMoves += abs(num - median);
        }

        return totalMoves;
    }
};
