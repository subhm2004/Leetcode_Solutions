class Solution {
public:
    int solve(int n, bool left_direction) {
        // Base case: sirf ek number bacha
        if (n == 1) return 1;

        if (left_direction) {
            // left_direction → Right
            return 2 * solve(n / 2, false);
        } else {
            // Right → left_direction
            if (n % 2 == 1)
                return 2 * solve(n / 2, true);
            else
                return 2 * solve(n / 2, true) - 1;
        }
    }

    int lastRemaining(int n) {
        return solve(n, true); // pehla step hamesha left_direction → Right hota hai
    }
};
