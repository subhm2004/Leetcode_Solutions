class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        vector<vector<int>> up(n + 1, vector<int>(m, 0));
        vector<vector<int>> down(n + 1, vector<int>(m, 0));

        // Length = 2
        for (int x = 0; x < m; x++) {

            for (int y = 0; y < m; y++) {

                if (x == y)
                    continue;

                if (x < y)
                    up[2][y] = (up[2][y] + 1) % MOD;
                else
                    down[2][y] = (down[2][y] + 1) % MOD;
            }
        }

        for (int i = 3; i <= n; i++) {

            vector<int> prefUp(m + 1, 0);
            vector<int> prefDown(m + 1, 0);

            for (int v = 0; v < m; v++) {
                prefUp[v + 1] =
                    (prefUp[v] + up[i - 1][v]) % MOD;

                prefDown[v + 1] =
                    (prefDown[v] + down[i - 1][v]) % MOD;
            }

            for (int y = 0; y < m; y++) {

                // up[i][y] =
                // sum of down[i-1][x] where x < y
                up[i][y] = prefDown[y];

                // down[i][y] =
                // sum of up[i-1][x] where x > y
                down[i][y] =
                    ((prefUp[m] - prefUp[y + 1]) % MOD + MOD) % MOD;
            }
        }

        long long ans = 0;

        if (n == 1) {
            ans = m;
        }
        else {

            for (int y = 0; y < m; y++) {

                ans =
                    (ans + up[n][y] + down[n][y]) % MOD;
            }
        }

        return ans;
    }
};