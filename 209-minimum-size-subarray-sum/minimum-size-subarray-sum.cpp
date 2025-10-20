class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;              // window ka start pointer
        int curr_sum = 0;       // window ke andar ka current sum
        int min_len = INT_MAX;     // answer store karega

        for (int right = 0; right < n; right++) {
            curr_sum += nums[right];   // right pointer se element add karo

            // Jab tak sum target se bada ya barabar ho jaaye,
            // window ko chhota karne ki koshish karo (left ko aage badhao)
            while (curr_sum >= target) {
                // minimum length update karo
                min_len = min(min_len, right - left + 1);

                // left element ko remove karo aur left aage badhao
                curr_sum -= nums[left];
                left++;
            }
        }

        // agar kabhi sum >= target nahi hua to return 0
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};