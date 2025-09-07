class Solution {
public:
    // function to calculate Xor of a subarray [l......r]
    int calculate_XOR(vector<int>& arr, int l, int r) {
        int xor_ans = 0;
        for (int i = l; i <= r; i++) {
            xor_ans ^= arr[i];
        }
        return xor_ans;
    }
    
    int solveRE(vector<int>& arr, int i, int k) {
        int n = arr.size();
        if (i >= n)
            return INT_MAX;

        if (k == 1) {
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
        
        for (int j = i; j <= n - k; j++) {
            int left_XOR = calculate_XOR(arr, i, j);
            int right = solveRE(arr, j + 1, k - 1);

            if (right != INT_MAX) {
                int max_XOR = max(left_XOR, right);
                min_max = min(min_max, max_XOR);
            }
        }
        return min_max;
    }
    
    int solveME(vector<int>& arr, int i, int k , vector<vector<int>>& dp) {
        int n = arr.size();
        if (i >= n)
            return INT_MAX;

        if (k == 1) {
            return calculate_XOR(arr, i, n - 1);
        }
        
        if(dp[i][k] != -1 ) return dp[i][k];
        
        int min_max = INT_MAX;
        
        
        for (int j = i; j <= n - k; j++) {
            int left_XOR = calculate_XOR(arr, i, j);
            int right = solveME(arr, j + 1, k - 1,dp);

            if (right != INT_MAX) {
                int max_XOR = max(left_XOR, right);
                min_max = min(min_max, max_XOR);
            }
        }
        return  dp[i][k] = min_max;
    }
    
    int minXor(vector<int>& arr, int k) {
        int n = arr.size();
        // return solveRE(arr, 0, k);
        
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solveME(arr,0,k,dp);
    }
};