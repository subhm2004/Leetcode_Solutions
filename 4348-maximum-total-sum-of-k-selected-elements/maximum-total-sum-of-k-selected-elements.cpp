class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        long long sum = 0;

        sort(nums.begin(), nums.end(), greater<>());

        int i = 0;

        while (k && i < n) {

            if (mul > 1) {
                sum += 1LL * mul * nums[i];
                mul--;
            } else {
                sum += nums[i];
            }

            i++;
            k--;
        }

        return sum;
    }
};