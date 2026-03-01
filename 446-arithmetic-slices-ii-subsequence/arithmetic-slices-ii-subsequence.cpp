class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                long long diff = 1LL * nums[i] - nums[j];

                int prev = dp[j].count(diff) ? dp[j][diff] : 0;

                ans += prev;

                dp[i][diff] += prev + 1;
            }
        }

        return (int)ans;
    }
};