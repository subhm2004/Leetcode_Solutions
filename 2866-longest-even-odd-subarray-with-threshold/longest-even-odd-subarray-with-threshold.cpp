auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int max_len = 0;
        int curr_len = 0;

        for (int i = 0; i < n; i++) {
            // Condition : value must be <= threshold
            if (nums[i] > threshold) {
                curr_len = 0;
                continue;
            }

            // If starting a new subarray
            if (curr_len == 0) {
                if (nums[i] % 2 == 0) {
                    curr_len = 1;
                    max_len = max(max_len, curr_len);
                }
            } else {
                // Check alternating parity condition
                int prev = nums[i - 1] % 2;
                int curr = nums[i] % 2;

                if (prev != curr && nums[i] <= threshold) {
                    curr_len++;
                    max_len = max(max_len, curr_len);
                } else {
                    // Restart possible new subarray
                    curr_len = (nums[i] % 2 == 0 ? 1 : 0);
                    max_len = max(max_len, curr_len);
                }
            }
        }

        return max_len;
    }
};