class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {

        long long even = -1e18;
        long long odd  = -1e18;

        if (nums[0] % 2 == 0)
            even = nums[0];
        else
            odd = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            long long val = nums[i];

            if (val % 2 == 0) {

                long long new_even = max(even + val, odd + val - x);

                even = max(even, new_even);
            }
            else {

                long long new_odd =  max(odd + val, even + val - x);

                odd = max(odd, new_odd);
            }
        }

        return max(even, odd);
    }
};