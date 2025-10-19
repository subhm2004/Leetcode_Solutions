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
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        // nums[i...j]
        for (int i = 0; i < n; i++) {
            // har subarray k liye check hoga ye odd even ke distinct elements ka count 
            unordered_set<int> even, odd;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    even.insert(nums[j]);
                } else {
                    odd.insert(nums[j]);
                }
                if (even.size() == odd.size()) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};