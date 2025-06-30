class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int left = 0, max_length = 0;

        // Step 2: Two-pointer approach
        for (int right = 0; right < nums.size(); right++) {
            while (nums[right] - nums[left] > 1) { // Difference > 1 toh left aage badhao
                left++;
            }

            // Step 3: Difference exactly 1 hai toh length update karo
            if (nums[right] - nums[left] == 1) {
                max_length = max(max_length, right - left + 1);
            }
        }
        return max_length;
    }
};
