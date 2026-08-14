class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {

        int n = nums.size();

        long long ans = LLONG_MIN;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        int j = 0;

        for (int i = 0; i < n; i++) {

            // nums[j] ko tabhi include karo
            // jab current index i ke saath distance >= m-1 ho
            if (i - j + 1 >= m) {

                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);

                ans = max(ans, 1LL * mini * nums[i]);
                ans = max(ans, 1LL * maxi * nums[i]);

                j++;
            }
        }

        return ans;
    }
};