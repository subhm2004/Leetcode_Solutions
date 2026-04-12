class Solution {
public:
    int dp[305][27][27];
    string word;

    // distance between two letters
    int dist(int a, int b) {

        if (a == -1 || b == -1)
            return 0;

        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(int i, int f1, int f2) {

        // all letters typed
        if (i == word.size())
            return 0;

        if (dp[i][f1 + 1][f2 + 1] != -1)
            return dp[i][f1 + 1][f2 + 1];

        int curr = word[i] - 'A';

        int finger_1_used = dist(f1, curr) + solve(i + 1, curr, f2);

        int finger_2_used = dist(f2, curr) + solve(i + 1, f1, curr);

        return dp[i][f1 + 1][f2 + 1] = min(finger_1_used, finger_2_used);
    }

    int minimumDistance(string w) {

        word = w;

        memset(dp, -1, sizeof(dp));

        return solve(0, -1, -1); // free fingers
    }
};