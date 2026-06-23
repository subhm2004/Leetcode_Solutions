class Solution {
public:
    const int MOD = 1e9 + 7;

    string s1, s2, evil;
    int n, m;

    int lps[55];
    int dp[505][55][2][2];

    void buildLPS() {

        int len = 0;
        lps[0] = 0;

        int i = 1;

        while (i < m) {

            if (evil[i] == evil[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {

                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int getNextMatch(int matched, char ch) {

        while (matched > 0 &&
               evil[matched] != ch) {

            matched = lps[matched - 1];
        }

        if (evil[matched] == ch)
            matched++;

        return matched;
    }

    int solve(int idx,
              int matched,
              bool tightLow,
              bool tightHigh) {

        if (matched == m)
            return 0; // evil mil gaya

        if (idx == n)
            return 1; // valid string

        if (dp[idx][matched][tightLow][tightHigh] != -1) {
            return dp[idx][matched][tightLow][tightHigh];
        }

        long long ans = 0;

        char low = tightLow ? s1[idx] : 'a';
        char high = tightHigh ? s2[idx] : 'z';

        for (char ch = low; ch <= high; ch++) {

            bool updatedLow =
                tightLow && (ch == s1[idx]);

            bool updatedHigh =
                tightHigh && (ch == s2[idx]);

            int updatedMatched =
                getNextMatch(matched, ch);

            ans += solve(idx + 1,
                         updatedMatched,
                         updatedLow,
                         updatedHigh);

            ans %= MOD;
        }

        return dp[idx][matched][tightLow][tightHigh] = ans;
    }

    int findGoodStrings(int n,
                        string s1,
                        string s2,
                        string evil) {

        this->n = n;
        this->s1 = s1;
        this->s2 = s2;
        this->evil = evil;

        m = evil.size();

        buildLPS();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, true, true);
    }
};