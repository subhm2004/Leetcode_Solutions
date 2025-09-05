class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int i = 0;
        int curr_OR = 0;

        for (int j = 0; j < n; j++) {
            curr_OR |= nums[j];  // window expand

            // shrink jab tak OR ≥ k
            while (i <= j && curr_OR >= k) {
                ans = min(ans, j - i + 1);

                // i ko move karo aur OR recompute
                int temp_OR = 0;
                for (int t = i + 1; t <= j; t++) {
                    temp_OR |= nums[t];
                }
                i++;
                curr_OR = temp_OR;
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};