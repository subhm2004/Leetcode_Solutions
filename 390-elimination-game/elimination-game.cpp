class Solution {
public:
    int solve(int n, bool left) {
        // Base case: sirf ek number bacha
        if (n == 1) return 1;

        if (left) {
            // Left → Right
            return 2 * solve(n / 2, false);
        } else {
            // Right → Left
            if (n % 2 == 1)
                return 2 * solve(n / 2, true);
            else
                return 2 * solve(n / 2, true) - 1;
        }
    }

    int lastRemaining(int n) {
        return solve(n, true); // pehla step hamesha Left → Right hota hai
    }
};
