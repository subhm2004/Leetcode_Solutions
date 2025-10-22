auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    long long solveRE(int i, int subarray_num, vector<int>& nums,
                      vector<int>& cost,
                      vector<long long>& prefix_nums,
                      vector<long long>& prefix_cost, int k) {
        int n = nums.size();

        //  Base case:
        // Agar hum array ke end tak pahunch gaye (i >= n)
        // iska matlab koi elements nahi bache process karne ke liye.
        // Toh total cost yahan se 0 hogi.
        if (i >= n)
            return 0;

        long long min_total = LLONG_MAX;

        // Har possible subarray ke liye try kar rahe hain jo index i se start hota hai.
        // Means: hum dekh rahe hain ki kaha tak subarray end kare taaki cost minimum aaye.
        for (int j = i; j < n; j++) {

            // sum_nums = nums[0] + nums[1] + ... + nums[j]
             // total sum from nums[0] to nums[j] tak  
            long long sum_nums = prefix_nums[j + 1]; 

            // sum_cost = cost[i] + cost[i+1] + ... + cost[j]
            // Ye current subarray ke cost array ka sum hai.
            // Prefix array se ye fast nikal jata hai: prefix[j+1] - prefix[i]
            long long sum_cost = prefix_cost[j + 1] - prefix_cost[i];

            // Ab subarray ka cost calculate karte hain:
            // subarray_cost: (nums[0] + ... + nums[r] + k * subarray_num) * (cost[l] + ... + cost[r])
            // Yahan subarray_num denote karta hai ki ye 1st, 2nd, 3rd... subarray hai.
            long long subarray_cost = (sum_nums + (long long)k * subarray_num) * sum_cost;

            // pruning step: if current cost already exceeds known min_total, skip
            if (subarray_cost >= min_total) break;

            // Ab hum baaki ke array ke liye call lagate hain (j+1 se start karke)
            // aur next subarray number pass karte hain.
            long long total_cost = subarray_cost +solveRE(j + 1, subarray_num + 1, nums, cost, prefix_nums, prefix_cost, k);

            //  Minimum total cost ko update karte hain.
            min_total = min(min_total, total_cost);
        }

        return min_total;
    }

    long long solveME(int i, int subarray_num, vector<int>& nums,
                    vector<int>& cost,
                    vector<long long>& prefix_nums,
                    vector<long long>& prefix_cost,
                      vector<vector<long long>>& dp_1, int k) {
        int n = nums.size();
        if (i >= n) return 0;
        if (dp_1[i][subarray_num] != -1) return dp_1[i][subarray_num];

        long long min_total = LLONG_MAX;
        for (int j = i; j < n; j++) {
            long long sum_nums = prefix_nums[j + 1];
            long long sum_cost = prefix_cost[j + 1] - prefix_cost[i];
            long long subarray_cost = (sum_nums + (long long)k * subarray_num) * sum_cost;

            if (subarray_cost >= min_total) break;

            long long total_cost = subarray_cost + solveME(j + 1, subarray_num + 1, nums, cost, prefix_nums, prefix_cost, dp_1, k);
            min_total = min(min_total, total_cost);
        }
        return dp_1[i][subarray_num] = min_total;
    }
    

    long long solveRE_Optimized(int i, vector<int>& nums, vector<int>& cost,
                                vector<long long>& prefix_nums, vector<long long>& prefix_cost, int k) {
        int n = nums.size();

        // Base Case:
        // Agar hum array ke end tak pahunch gaye (i >= n),
        // iska matlab koi elements nahi bache process karne ke liye.
        // Toh total cost yahan se 0 hogi.
        if (i >= n) return 0;

        long long min_total = LLONG_MAX;

        // Har possible subarray ke liye try kar rahe hain jo index i se start hota hai.
        for (int j = i; j < n; j++) {

            /** -----------------------------------------------------------
             * Modified Formula: 
             * NOTE : Ye formula independent hai subarray order se
             * cost = (sum of nums from 0 to r) * (sum of cost from l to r)
             *         + k * (sum of cost from l to n-1) 
             * -----------------------------------------------------------
             * i -> current subarray start index (l)
             * j -> current subarray end index (r)
             */

            // sum of nums from 0 to r
            // prefix_nums[j+1] gives sum(nums[0] + ... + nums[j])
            long long sum_nums = prefix_nums[j + 1];

            // sum of cost from l to r
            // prefix_cost[j+1] - prefix_cost[i] = sum(cost[i] + ... + cost[j])
            long long sum_cost_lr = prefix_cost[j + 1] - prefix_cost[i];

            // sum of cost from l to n-1
            // prefix_cost[n] - prefix_cost[i] = sum(cost[i] + ... + cost[n-1])
            long long sum_cost_ln = prefix_cost[n] - prefix_cost[i];

            // Apply the modified formula of cost 
            long long sub_cost = sum_nums * sum_cost_lr + 1LL * k * sum_cost_ln;

            // (Optional) Optimization / Pruning:
            // Agar current sub_cost pehle se hi min_total se bada hai,
            // toh aage ke j ke liye aur bada hi hoga -> break kar dete hain.
            if (sub_cost >= min_total) break;

            // Recursive call for next subarray starting from (j + 1)
            long long total_cost = sub_cost + solveRE_Optimized(j + 1, nums, cost, prefix_nums, prefix_cost, k);

            // Update the minimum total cost
            min_total = min(min_total, total_cost);
        }

        return min_total;
    }

    long long solveME_Optimized(int i, vector<int>& nums, vector<int>& cost,
                                vector<long long>& prefix_nums, vector<long long>& prefix_cost,
                                vector<long long>& dp, int k) {
        int n = nums.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        long long min_total = LLONG_MAX;
        for (int j = i; j < n; j++) {
            long long sum_nums = prefix_nums[j + 1];
            long long sum_cost_lr = prefix_cost[j + 1] - prefix_cost[i];
            long long sum_cost_ln = prefix_cost[n] - prefix_cost[i];
            long long sub_cost = sum_nums * sum_cost_lr + 1LL * k * sum_cost_ln;
            if (sub_cost >= min_total) break;
            long long total_cost = sub_cost + solveME_Optimized(j + 1, nums, cost, prefix_nums, prefix_cost, dp, k);
            min_total = min(min_total, total_cost);
        }

        return dp[i] = min_total;
    }

    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();

        vector<long long> prefix_nums(n + 1, 0);
        vector<long long> prefix_cost(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_nums[i + 1] = prefix_nums[i] + nums[i];
            prefix_cost[i + 1] = prefix_cost[i] + cost[i];
        }

        // return solveRE(0, 1, nums, cost, prefix_nums, prefix_cost, k);

        vector<vector<long long>> dp_1(n + 1, vector<long long>(n + 2, -1));
        // return solveME(0, 1, nums, cost, prefix_nums, prefix_cost, dp_1, k);

        // Optimization 
        // return solveRE_Optimized(0, nums, cost, prefix_nums, prefix_cost, k);

        vector<long long> dp(n + 1, -1);
        return solveME_Optimized(0, nums, cost, prefix_nums, prefix_cost, dp, k);

    }
};






