typedef long long ll;
class Solution {
public:
    ll solveME(int i, int subarray_num, vector<int>& nums,
                    vector<int>& cost,
                    vector<ll>& prefix_nums,
                    vector<ll>& prefix_cost,
                      vector<vector<ll>>& dp_1, int k) {
        int n = nums.size();
        if (i >= n) return 0;
        if (dp_1[i][subarray_num] != -1) return dp_1[i][subarray_num];

        ll min_total = LLONG_MAX;
        for (int j = i; j < n; j++) {
            ll sum_nums = prefix_nums[j + 1];
            ll sum_cost = prefix_cost[j + 1] - prefix_cost[i];
            ll subarray_cost = (sum_nums + (ll)k * subarray_num) * sum_cost;

            if (subarray_cost >= min_total) break;

            ll total_cost = subarray_cost + solveME(j + 1, subarray_num + 1, nums, cost, prefix_nums, prefix_cost, dp_1, k);
            min_total = min(min_total, total_cost);
        }
        return dp_1[i][subarray_num] = min_total;
    }
    
    ll solveME_Optimized(int i, vector<int>& nums, vector<int>& cost,
                                vector<ll>& prefix_nums, vector<ll>& prefix_cost,
                                vector<ll>& dp, int k) {
        int n = nums.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        ll min_total = LLONG_MAX;
        for (int j = i; j < n; j++) {

            /*
            Modified Cost Formula: (Independent of subarray_num)
            Cost = (sum of nums from 0 to r) * (sum of cost from l to r) + k * (sum of cost from l to n-1).
            i -> current subarray start index (l)
            j -> current subarray end index (r)
            */

            ll sum_nums = prefix_nums[j + 1];
            ll sum_cost_lr = prefix_cost[j + 1] - prefix_cost[i];
            ll sum_cost_ln = prefix_cost[n] - prefix_cost[i];
            ll sub_cost = sum_nums * sum_cost_lr + 1LL * k * sum_cost_ln;
            if (sub_cost >= min_total) break;
            ll total_cost = sub_cost + solveME_Optimized(j + 1, nums, cost, prefix_nums, prefix_cost, dp, k);
            min_total = min(min_total, total_cost);
        }

        return dp[i] = min_total;
    }

    ll minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();

        vector<ll> prefix_nums(n + 1, 0);
        vector<ll> prefix_cost(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_nums[i + 1] = prefix_nums[i] + nums[i];
            prefix_cost[i + 1] = prefix_cost[i] + cost[i];
        }

        vector<vector<ll>> dp(n + 1, vector<ll>(n + 2, -1));
        // return solveME(0, 1, nums, cost, prefix_nums, prefix_cost, dp, k);

        vector<ll> dp_1(n + 1, -1);
        return solveME_Optimized(0, nums, cost, prefix_nums, prefix_cost, dp_1, k);
    }
};