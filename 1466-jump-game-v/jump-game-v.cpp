class Solution {
public:
    int n, d;
    int dp[1001];          
    vector<int> arr;

    int solve(int i) {
        if (dp[i] != -1) return dp[i];
        // BC (agar right side jump possible nhi hai or left side jump bhi possiblenhi hai to ye apna current index wala count return krega )
        int ans = 1; // khud wala index count

        // right side
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            // hight to lower par hi jump kar skte hai lower to higher building par nhi 
            if (arr[j] >= arr[i]) break;
            ans = max(ans, 1 + solve(j));
        }

        // left side
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i]) break;
            ans = max(ans, 1 + solve(j));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        this->arr = arr;
        n = arr.size();
        this->d = d;

        memset(dp, -1, sizeof(dp));

        int result = 1;
        for (int i = 0; i < n; i++) {
            result = max(result, solve(i));
        }

        return result;
    }
};