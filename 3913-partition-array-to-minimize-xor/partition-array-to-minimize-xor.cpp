class Solution {
public:
    // function to calculate Xor of a subarray [l......r]

    int calculate_XOR(vector<int>& arr, int l, int r) {
        int xor_ans = 0;
        for (int i = l; i <= r; i++)
            xor_ans ^= arr[i];
        return xor_ans;
    }

    int solveRE(vector<int>& arr, int i, int parts) {
        int n = arr.size();

        if (i >= n) return INT_MAX;

        if (parts == 1) {
            return calculate_XOR(arr, i, n - 1);
        }

        int min_max = INT_MAX;
        //[i....................n]
        // jab i se j tak ek partition ho chuka hai [i.......j] [j+1.................n]
        //                                          1 partition        k-1 partition
        // n - (j+1) >= k-1
        // n - j - 1 >= k-1
        // n - j >= k 
        // j <= n - k

        for (int j = i; j <= n - parts; j++) {

            int left_xor = calculate_XOR(arr, i, j);
            int right   = solveRE(arr, j + 1, parts - 1);

            if (right != INT_MAX) {
                int curr_max = max(left_xor, right);
                min_max = min(min_max, curr_max);
            }
        }

        return min_max;
    }

    int solveME(vector<int>& arr, int i, int parts,
                vector<vector<int>>& dp) {

        int n = arr.size();

        if (i >= n) return INT_MAX;

        if (parts == 1) {
            return calculate_XOR(arr, i, n - 1);
        }

        if (dp[i][parts] != -1)
            return dp[i][parts];

        int min_max = INT_MAX;

        for (int j = i; j <= n - parts; j++) {

            int left_xor = calculate_XOR(arr, i, j);
            int right   = solveME(arr, j + 1, parts - 1, dp);

            if (right != INT_MAX) {
                int curr_max = max(left_xor, right);
                min_max = min(min_max, curr_max);
            }
        }

        return dp[i][parts] = min_max;
    }

    int minXor(vector<int>& arr, int k) {

        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return solveME(arr, 0, k, dp);
    }
};
