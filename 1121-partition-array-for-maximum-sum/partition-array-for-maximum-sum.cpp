//https://www.youtube.com/watch?v=LvvIcZWtuoY&t=46s
class Solution {
public:
    int solveRE(int i, vector<int>& arr, int k) {
        if (i == arr.size())
            return 0;  // agar end tak pahuch gaye, aur kuch partition nahi bacha, to 0 return

        int max_sum = 0;
        int max_element = INT_MIN;

        // har possible partition length (1 se k tak) check karo
        for (int j = 1; j <= k && i + j <= arr.size(); ++j) {
            max_element = max(max_element, arr[i + j - 1]);  // current partition ka max element
            // next recursion call + current partition ka contribution
            max_sum = max(max_sum, solveRE(i + j, arr, k) + max_element * j);
        }

        return max_sum;
    }

     int solveME(int i, vector<int>& arr, int k, vector<int>& dp) {
        if (i == arr.size())
            return 0;

        if (dp[i] != -1)
            return dp[i]; 
        int max_sum = 0;
        int max_element = INT_MIN;

        for (int j = 1; j <= k && i + j <= arr.size(); ++j) {
            max_element = max(max_element, arr[i + j - 1]);
            max_sum = max(max_sum, solveME(i + j, arr, k, dp) + max_element * j);
        }

        return dp[i] = max_sum;   
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // return solveRE(0, arr, k);

        vector<int> dp(n, -1);
        return solveME(0, arr, k, dp);
    }
};
