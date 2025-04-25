typedef long long ll;

class Solution {
public:
    // Recursive function with memoization
    // i: current index
    // isMax: agar true hai toh max product chahiye, else min product
    ll solveME(const vector<int>& nums, int i, bool isMax, vector<vector<ll>>& dp) {
        // Base case: agar i array ke bahar chala gaya toh
        if (i < 0)
            return isMax ? LLONG_MIN : LLONG_MAX;

        // Agar value pehle se calculate ho chuki hai toh wahi return karo
        if (dp[isMax][i] != LLONG_MAX)
            return dp[isMax][i];

        ll curr = nums[i];
        ll maxProd = curr, minProd = curr;

        // Agar i > 0 hai toh pehle ke max aur min products nikal ke current ke saath combine karo
        if (i > 0) {
            ll prevMax = solveME(nums, i - 1, true, dp);   // Previous max product
            ll prevMin = solveME(nums, i - 1, false, dp);  // Previous min product

            // Teen possibilities: 
            // 1. Sirf current element
            // 2. current * previous max
            // 3. current * previous min
            maxProd = max(curr, max(curr * prevMax, curr * prevMin));
            minProd = min(curr, min(curr * prevMax, curr * prevMin));
        }

        // DP array mein result store karo taaki dobara calculate na ho
        dp[true][i] = maxProd;
        dp[false][i] = minProd;

        // isMax ke basis pe max ya min product return karo
        return isMax ? maxProd : minProd;
    }

    ll maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        // DP array: 2 rows → 0 for min, 1 for max
        // Har index ke liye initially LLONG_MAX set kiya hai (means not computed yet)
        vector<vector<ll>> dp(2, vector<ll>(n, LLONG_MAX));

        ll ans = LLONG_MIN;

        // Har index tak ka max product calculate karke global answer update karo
        for (int i = 0; i < n; ++i) {
            ll maxProdAtI = solveME(nums, i, true, dp);  // i-th index tak max product ending at i
            ans = max(ans, maxProdAtI);  // Global max update karo
        }

        return ans;
    }
};
