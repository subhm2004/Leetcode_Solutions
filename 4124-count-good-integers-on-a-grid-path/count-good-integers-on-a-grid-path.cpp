// isme started ki need hi nhi hai 
class Solution {
public:
    long long dp[17][11][8][2];
    string s;

    vector<int> path;

    long long solve(int idx, int prev_digit, int pos, bool tight) {

        if (idx == 16) {
            return 1;
        }

        int p = prev_digit + 1;

        if (dp[idx][p][pos][tight] != -1)
            return dp[idx][p][pos][tight];

        long long ans = 0;

        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            bool updated_tight = tight && (d == limit);

            if (pos < 7 && idx == path[pos]) {

                if (prev_digit == -1 || d >= prev_digit) {
                    ans += solve(idx + 1, d, pos + 1, updated_tight);
                }

            } else {
                ans += solve(idx + 1, prev_digit, pos, updated_tight);
            }
        }

        return dp[idx][p][pos][tight] = ans;
    }

    long long count(long long x) {

        if (x < 0) return 0;

        s = to_string(x);

        while (s.size() < 16)
            s = '0' + s;

        memset(dp, -1, sizeof(dp));

        return solve(0, -1, 0, true);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions) {

        path.clear();

        int row = 0, col = 0;

        path.push_back(0);

        for (char ch : directions) {

            if (ch == 'D') row++;
            else col++;

            path.push_back(row * 4 + col);
        }

        return count(r) - count(l - 1);
    }
};