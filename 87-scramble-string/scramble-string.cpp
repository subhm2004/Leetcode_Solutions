class Solution {
public:
    unordered_map<string, bool> dp;

    bool solve(string a, string b) {

        string key = a + "|" + b;
        if (dp.count(key)) return dp[key];

        // same string
        if (a == b) return dp[key] = true;

        int n = a.size();

        // try krte hai all partitions
        for (int k = 1; k < n; k++) {

            // no swap
            if (solve(a.substr(0, k), b.substr(0, k)) && solve(a.substr(k), b.substr(k)))
                return dp[key] = true;

            // swap
            if (solve(a.substr(0, k), b.substr(n - k)) && solve(a.substr(k), b.substr(0, n - k)))
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};