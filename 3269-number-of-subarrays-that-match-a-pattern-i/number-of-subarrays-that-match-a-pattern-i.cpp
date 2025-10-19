/*
Pattern me sirf -1, 0, 1 ho sakte hain:

1 → next number bada hona chahiye (nums[i+1] > nums[i])

0 → next number equal hona chahiye (nums[i+1] == nums[i])

-1 → next number chhota hona chahiye (nums[i+1] < nums[i])
*/
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int count = 0;

        for (int i = 0; i <= n - m - 1; i++) { // subarray start index
            bool match = true;
            for (int k = 0; k < m; k++) { // pattern check
                if (pattern[k] == 1 && nums[i + k + 1] <= nums[i + k]) {
                    match = false;
                    break;
                }
                if (pattern[k] == 0 && nums[i + k + 1] != nums[i + k]) {
                    match = false;
                    break;
                }
                if (pattern[k] == -1 && nums[i + k + 1] >= nums[i + k]) {
                    match = false;
                    break;
                }
            }
            if (match)
                count++;
        }

        return count;
    }
};