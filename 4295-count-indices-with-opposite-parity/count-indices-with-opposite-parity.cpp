class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int even_count = 0;
        int odd_count = 0;

        // traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] % 2 == 0) {
                // even → need odd on right
                ans[i] = odd_count;
                even_count++;
            } else {
                // odd → need even on right
                ans[i] = even_count;
                odd_count++;
            }
        }

        return ans;
    }
};