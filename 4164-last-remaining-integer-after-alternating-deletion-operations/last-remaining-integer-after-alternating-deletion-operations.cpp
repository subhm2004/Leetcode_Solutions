class Solution {
public:
    long long solve(long long n, bool left_dir) {
        // base case: index 0
        if (n == 1) return 0;

        // LEFT → RIGHT
        if (left_dir) {
            // index mapping: 2 * x
            return 2 * solve((n + 1) / 2, false);
        }
        // RIGHT → LEFT
        else {
            if (n % 2 == 0) {
                // even n → 2*x + 1
                return 2 * solve((n + 1) / 2, true) + 1;
            } else {
                // odd n → 2*x
                return 2 * solve((n + 1) / 2, true);
            }
        }
    }

    long long lastInteger(long long n) {
        // +1 because index → actual number
        return solve(n, true) + 1;
    }
};
