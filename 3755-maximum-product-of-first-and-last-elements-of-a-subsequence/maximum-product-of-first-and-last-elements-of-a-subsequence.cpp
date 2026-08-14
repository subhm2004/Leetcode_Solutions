class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {

        int n = nums.size();

        long long ans = LLONG_MIN;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        int i = m - 1;
        int j = 0;

        while (i < n) {

            mini = min(mini, nums[j]);
            maxi = max(maxi, nums[j]);

            ans = max(ans, 1LL * mini * nums[i]);
            ans = max(ans, 1LL * maxi * nums[i]);

            i++;
            j++;
        }

        return ans;
    }
};