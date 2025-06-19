class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  
        int max_Count = 0;
        int left = 0;

         for (int right = 0; right < nums.size(); right++) {
            // Shrink window from left if it exceeds beauty limit
            while (nums[right] - nums[left] > 2 * k) { // [nums[right] - k, nums[left] + k] ke bahar aa rhi hai values
                left++;
            }

            max_Count = max(max_Count, right - left + 1);
        }

        return max_Count;
    }
};
