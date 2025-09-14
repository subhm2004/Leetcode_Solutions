class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp; 
    // dp[idx][last1][last2] = number of stable subsequences starting from idx
    // last1 = parity of last picked element (0 = even, 1 = odd, 2 = no element)
    // last2 = parity of second last picked element (same encoding)

    int solveME(vector<int>& arr, int idx, int last1, int last2) {
        // base case: end of array
        if (idx == arr.size()) {
            // agar subsequence empty hai (koi pick nahi kiya) toh invalid
            return (last1 == 2) ? 0 : 1;
        }

        // memoization check
        if (dp[idx][last1][last2] != -1) 
            return dp[idx][last1][last2];

        // choice 1: skip current element
        long long ans = solveME(arr, idx + 1, last1, last2);

        // choice 2: pick current element
        int parity = arr[idx] % 2;
        // ensure 3 consecutive same parity na ho
        if (!(last1 == parity && last2 == parity)) {
            ans = (ans + solveME(arr, idx + 1, parity, last1)) % MOD;
        }

        return dp[idx][last1][last2] = ans;
    }

    int countStableSubsequences(vector<int>& arr) {
        int n = arr.size();
        // dp ko initialize karo -1 se
        dp.assign(n + 1, vector<vector<int>>(3, vector<int>(3, -1)));
        // initially koi element pick nahi hua (2 = no element)
        return solveME(arr, 0, 2, 2);
    }
};
