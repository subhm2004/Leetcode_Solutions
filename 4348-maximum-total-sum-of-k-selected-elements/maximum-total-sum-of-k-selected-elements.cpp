class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        const int MAX = 100000;
        vector<int> freq(MAX + 1, 0);

        for (int x : nums)
            freq[x]++;

        long long sum = 0;

        for (int val = MAX; val >= 1 && k > 0; val--) {

            while (freq[val] > 0 && k > 0) {

                if (mul > 1) {
                    sum += 1LL * val * mul;
                    mul--;
                }
                else {
                    sum += val;
                }

                freq[val]--;
                k--;
            }
        }

        return sum;
    }
};