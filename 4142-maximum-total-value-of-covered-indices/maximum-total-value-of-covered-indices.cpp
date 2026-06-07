class Solution {
public:
    vector<vector<long long>> dp;

    // i  = current index
    // taken = 1 means token at i+1 has already moved to i (used kiya ja chuka)
    //       = 0 means koi token bahar se nahi aaya
    long long solve(int i, vector<int>& nums, string& s, int taken) {
        int n = s.size();

        // Base case: saare indices process ho gaye
        if (i >= n) return 0;

        // Memoization: already computed
        if (dp[i][taken] != -1) return dp[i][taken];

        // ─────────────────────────────────────────────────
        // CHOICE 1: Index i ko skip karo (kuch mat lo)
        // Aage badho, koi token carry nahi
        // ─────────────────────────────────────────────────
        long long ans = solve(i + 1, nums, s, 0);

        // ─────────────────────────────────────────────────
        // CHOICE 2: Index i ka apna token hai (s[i]='1')
        //           AND koi bahar se token nahi aaya (taken=0)
        //           → Token apni jagah raha, nums[i] lo
        // ─────────────────────────────────────────────────
        if (s[i] == '1' && !taken) {
            ans = max(ans, (long long)nums[i] + solve(i + 1, nums, s, 0));
        }

        // ─────────────────────────────────────────────────
        // CHOICE 3: Right neighbour (i+1) ka token left move kare
        //           → i+1 pe token hai (s[i+1]='1')
        //           → Wo token i pe aata hai → nums[i] lo
        //           → taken=1 pass karo taaki i+1 pe
        //             dobara count na ho
        // ─────────────────────────────────────────────────
        if (i + 1 < n && s[i + 1] == '1') {
            ans = max(ans, (long long)nums[i] + solve(i + 1, nums, s, 1));
        }

        return dp[i][taken] = ans;
    }

    long long maxTotal(vector<int>& nums, string s) {
        int n = s.size();

        // dp[i][taken] → -1 matlab abhi compute nahi hua
        dp.assign(n, vector<long long>(2, -1));

        return solve(0, nums, s, 0);
    }
};