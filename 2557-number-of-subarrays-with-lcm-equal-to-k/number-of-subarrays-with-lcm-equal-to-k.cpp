class Solution {
public:
    int GCD(int a, int b) {
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }

    long long LCM(long long a, long long b) { return (a * b) / GCD(a, b); }

    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int curr_lcm = nums[i];

            for (int j = i; j < n; ++j) {
                if (k % nums[j] != 0)
                    break;

                curr_lcm = LCM(curr_lcm, nums[j]);

                if (curr_lcm == k) // valid subarray
                    count++;
            }
        }

        return count;
    }
};