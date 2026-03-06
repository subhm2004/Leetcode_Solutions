class Solution {
public:
    int largest_segment(vector<int>& arr, int num) {
        int max_count = 0;
        int count = 0;
        for (int v : arr) {
            if (v == num) {
                count++;
                max_count = max(max_count, count);

            } else {
                count = 0;
            }
        }
        return max_count;
    }
    int findMaxConsecutiveOnes(vector<int>& nums) {
        return largest_segment(nums, 1);
    }
};