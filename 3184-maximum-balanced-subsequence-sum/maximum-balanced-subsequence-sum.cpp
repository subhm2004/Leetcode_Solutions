typedef long long ll;
class Solution {  
public:
    ll solveRE(vector<int>& nums, int curr_sumr, int prev) {
        if (curr_sumr >= nums.size()) {
            return INT_MIN;
        }

        ll include = INT_MIN;
        if (prev == -1 || (nums[curr_sumr] - nums[prev] >= curr_sumr - prev)) {
            include = nums[curr_sumr] + max(0LL, solveRE(nums, curr_sumr + 1, curr_sumr));
        }

        ll exclude = solveRE(nums, curr_sumr + 1, prev);

        return max<ll>(include, exclude);
    }

    ll solveME(vector<int>& nums, int curr_sumr, int prev,
                      vector<vector<ll>>& dp) {
        if (curr_sumr >= nums.size()) {
            return INT_MIN;
        }

        if (dp[curr_sumr][prev + 1] != LLONG_MIN) {
            return dp[curr_sumr][prev + 1];
        }

        ll include = INT_MIN;
        if (prev == -1 || (nums[curr_sumr] - nums[prev] >= curr_sumr - prev)) {
            include = nums[curr_sumr] + max(0LL, solveME(nums, curr_sumr + 1, curr_sumr, dp));
        }

        ll exclude = solveME(nums, curr_sumr + 1, prev, dp);

        return dp[curr_sumr][prev + 1] = max<ll>(include, exclude);
    }

    ll solve_Bottom_Up(vector<int>& nums) {
        int n = nums.size();
        vector<ll> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            dp[i] = nums[i];
        }

        ll maxSum = nums[0];

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] - i >= nums[j] - j) {
                    dp[i] = max(dp[i], dp[j] + nums[i]);
                }
            }
            maxSum = max<ll>(maxSum, dp[i]);
        }

        return maxSum;
    }

     ll optmized_Solution(vector<int>& nums) {
        int n = nums.size();
        map<int, ll> bestSum;  // (nums[i]-i , Sum) 
        ll ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            ll curr_sum = nums[i];

            auto it = bestSum.upper_bound(key); // it -> bestSum.first 
            if (it != bestSum.begin()) {
                --it;
                curr_sum += it->second;
            }

            bestSum[key] = max(bestSum[key], curr_sum);

            it = bestSum.upper_bound(key);
            while (it != bestSum.end() && it->second <= curr_sum) {
                bestSum.erase(it++);
            }

            ans = max(ans, curr_sum);
        }

        return ans;
    }

    ll maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        // return solveRE(nums, 0, -1);
        // vector<vector<ll>> dp(n, vector<ll>(n + 1, LLONG_MIN));

        // ll ans = solveME(nums, 0, -1, dp);
        // return (ans == INT_MIN) ? 0 : ans;
        // return solve_Bottom_Up(nums);
        return optmized_Solution(nums);

    }
};
