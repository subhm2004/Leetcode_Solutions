class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        const long long NEG = -4e18;

        vector<long long> inc1(n, NEG);
        vector<long long> dec2(n, NEG);
        vector<long long> inc3(n, NEG);

        for (int i = 1; i < n; i++) {

            // -------- phase 1 : increasing --------
            if (nums[i - 1] < nums[i]) {

                long long start_new = nums[i - 1] + nums[i];

                long long extend = NEG;
                if (inc1[i - 1] != NEG)
                    extend = inc1[i - 1] + nums[i];

                inc1[i] = max(start_new, extend);
            }

            // -------- phase 2 : decreasing --------
            if (nums[i - 1] > nums[i]) {

                long long best_prev_sum = NEG;

                if (dec2[i - 1] != NEG)
                    best_prev_sum = dec2[i - 1];

                if (inc1[i - 1] != NEG)
                    best_prev_sum = max(best_prev_sum, inc1[i - 1]);

                if (best_prev_sum != NEG)
                    dec2[i] = best_prev_sum + nums[i];
            }

            // -------- phase 3 : increasing again --------
            if (nums[i - 1] < nums[i]) {

                long long best_prev_sum = NEG;

                if (inc3[i - 1] != NEG)
                    best_prev_sum = inc3[i - 1];

                if (dec2[i - 1] != NEG)
                    best_prev_sum = max(best_prev_sum, dec2[i - 1]);

                if (best_prev_sum != NEG)
                    inc3[i] = best_prev_sum + nums[i];
            }
        }

        long long ans = NEG;
        for (int i = 0; i < n; i++)
            ans = max(ans, inc3[i]);

        return ans;
    }
};