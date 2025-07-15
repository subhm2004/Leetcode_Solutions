class Solution {
public:
     int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int curr_gcd = 0;

            for (int j = i; j < n; ++j) {
                curr_gcd = GCD(curr_gcd, nums[j]);

                if (curr_gcd == k) count++;        // Valid subarray
            }
        }

        return count;
    }
};
