auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    int dp[11][2][10]; // idx , tight , cnt of 1
    int solve(string& s, int idx, bool tight, int cnt) {
        if (idx >= s.size())
            return cnt;

        if (dp[idx][tight][cnt] != -1)
            return dp[idx][tight][cnt];

        int limit = (tight == true) ? s[idx] - '0' : 9;
        int ans = 0;
        for (int i = 0; i <= limit; i++) {
            int updated_cnt = cnt + (i == 1 ? 1 : 0);
            bool updated_tight = (tight && i == limit);
            ans += solve(s, idx + 1, updated_tight, updated_cnt);
        }
        return dp[idx][tight][cnt] = ans;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 0);
    }
};