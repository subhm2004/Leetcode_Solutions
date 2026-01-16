class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == m || j == n)
            return -1e9; // big negative to keep non-empty subseq constraint

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int val = nums1[i] * nums2[j];

        // Option 1 : take both
        int take_ij = val + max(solve(nums1, nums2, i+1, j+1), 0);

        // Option 2 : skip nums2[j]
        int skip2 = solve(nums1, nums2, i, j+1);

        // Option 3 : skip nums1[i]
        int skip1 = solve(nums1, nums2, i+1, j);

        return dp[i][j] = max({val, take_ij, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        dp.assign(m, vector<int>(n, INT_MIN));  

        return solve(nums1, nums2, 0, 0);
    }
};
