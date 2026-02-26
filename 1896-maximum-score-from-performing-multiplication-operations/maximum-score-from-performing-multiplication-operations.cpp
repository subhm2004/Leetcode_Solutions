class Solution {
public:
    int dp[305][305];
    vector<int> nums, mult;
    int n, m;

    int solve(int i, int l) {

        // all multipliers used
        if (i == m)
            return 0;

        if (dp[i][l] != -1)
            return dp[i][l];

        /*
        -------- Derivation of r --------

        total removed elements = i
        left removed  = l
        right removed = i - l

        original right index = n - 1

        after removing (i-l) from right:

        r = (n - 1) - (i - l)
        
        */

        int r = n - 1 - (i - l);

        // choose left
        int take_left = mult[i] * nums[l] + solve(i + 1, l + 1);

        // choose right
        int take_right = mult[i] * nums[r] + solve(i + 1, l);

        return dp[i][l] = max(take_left, take_right);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        this-> nums = nums;
        mult = multipliers;

        n = nums.size();
        m = mult.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0);
    }
};

