class Solution {     // Binary search + dp se hoga ye + hash map use hora hai
public:
using ll = long long;
    long long solveRE(vector<int>& nums, int curr, int prev) {
        if (curr >= nums.size()) {
            return INT_MIN;
        }

        long long include = INT_MIN;
        if (prev == -1 || (nums[curr] - nums[prev] >= curr - prev)) {
            include = nums[curr] + max(0LL, solveRE(nums, curr + 1, curr));
        }

        long long exclude = solveRE(nums, curr + 1, prev);

        return max(include, exclude);
    }

    long long solveME(vector<int>& nums, int curr, int prev, vector<vector<long long>>& dp) {
        if (curr >= nums.size()) {
            return INT_MIN;
        }

        if (dp[curr][prev + 1] != LLONG_MIN) {
            return dp[curr][prev + 1];
        }

        long long include = INT_MIN;
        if (prev == -1 || (nums[curr] - nums[prev] >= curr - prev)) {
            include = nums[curr] + max(0LL, solveME(nums, curr + 1, curr, dp));
        }

        long long exclude = solveME(nums, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(include, exclude);
    }

    long long solve_Bottom_Up_1(vector<int>& nums) { // dp wale me values sath me daal rhe hai hum dp wale me phl ebhi daal skte the values
        int n = nums.size();
        vector<long long> dp(n, 0);
        dp[0] = nums[0];
        long long maxSum = nums[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = nums[i];
            for (int j = 0; j < i; ++j) {
                if (nums[i] - i >= nums[j] - j) {
                    dp[i] = max(dp[i], dp[j] + nums[i]);
                }
            }
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }

        long long solve_Bottom_Up_2(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(nums.begin(), nums.end()); // dp[i] = nums[i] initially
        long long maxSum = dp[0];

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] - i >= nums[j] - j) {
                    dp[i] = max(dp[i], dp[j] + nums[i]);
                }
            }
            maxSum = max(maxSum, dp[i]);
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

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<long long>> dp(n, vector<long long>(n + 1, LLONG_MIN));

        // long long result = solveME(nums, 0, -1, dp);
        // return (result == INT_MIN) ? 0 : result;
        // return solve_Bottom_Up(nums);
        // return solve_Bottom_Up_2(nums);
        return optmized_Solution(nums);
    }
};
