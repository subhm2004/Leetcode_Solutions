class Solution {
public:
    static const int MOD = 1e9 + 7;
    int n;
    long long dp_sum[105][105];    // -2 => not computed, -1 => no path, >=0 => max sum
    long long dp_count[105][105];  // max sum ke paths ka count

    // solve(i, j) => {maxSum, count} from (i,j) to E
    pair<long long, long long> solve(int i, int j, vector<string>& board) {
        // Out of board ya obstacle => koi path nahi
        if (i < 0 || j < 0 || board[i][j] == 'X') {
            return {-1, 0};
        }

        // Base case: E pe pahunch gaye
        if (i == 0 && j == 0) {
            return {0, 1};
        }

        // Memo check: -2 nahi hai matlab pehle compute ho chuka
        if (dp_sum[i][j] != -2) {
            return {dp_sum[i][j], dp_count[i][j]};
        }

        // Teeno moves: up, left, up-left
        pair<long long, long long> up       = solve(i - 1, j,     board);
        pair<long long, long long> left     = solve(i,     j - 1, board);
        pair<long long, long long> diagonal = solve(i - 1, j - 1, board);

        long long best = -1;
        long long ways = 0;

        if (up.first > best) {
            best = up.first;
            ways = up.second;
        } else if (up.first == best && best != -1) {
            ways = (ways + up.second) % MOD;
        }

        if (left.first > best) {
            best = left.first;
            ways = left.second;
        } else if (left.first == best && best != -1) {
            ways = (ways + left.second) % MOD;
        }

        if (diagonal.first > best) {
            best = diagonal.first;
            ways = diagonal.second;
        } else if (diagonal.first == best && best != -1) {
            ways = (ways + diagonal.second) % MOD;
        }

        if (best == -1) {
            // Yahan se E tak koi rasta nahi — ye bhi memoize hota hai!
            dp_sum[i][j] = -1;
            dp_count[i][j] = 0;
        } else {
            long long cellVal = 0;
            if (board[i][j] != 'S') {
                cellVal = board[i][j] - '0';
            }
            dp_sum[i][j] = best + cellVal;
            dp_count[i][j] = ways;
        }

        return {dp_sum[i][j], dp_count[i][j]};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();

        // Sab -2 se init: "not computed"
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp_sum[i][j] = -2;
            }
        }

        pair<long long, long long> ans = solve(n - 1, n - 1, board);

        if (ans.first == -1) {
            return {0, 0};
        }
        return {(int)ans.first, (int)(ans.second % MOD)};
    }
};