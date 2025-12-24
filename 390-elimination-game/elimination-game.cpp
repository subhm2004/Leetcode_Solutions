class Solution {
public:
    int solve(int n, bool left_direction) {
        // Base case: agar sirf ek element bacha hai to wahi answer hoga
        if (n == 1) return 1;

        if (left_direction) {
            // Agar direction Left → Right hai:
            // hamesha head shift hota hai
            // isliye answer = 2 * solve(n/2, opposite direction)
            return 2 * solve(n / 2, false);
        } else {
            // Agar direction Right → Left hai:
            if (n % 2 == 1)
                // Agar n odd hai to head bhi shift hoga
                // answer = 2 * solve(n/2, opposite direction)
                return 2 * solve(n / 2, true);
            else
                // Agar n even hai to head shift nahi hoga
                // isliye answer = 2 * solve(n/2, opposite direction) - 1
                return 2 * solve(n / 2, true) - 1;
        }
    }

    int lastRemaining(int n) {
        // Pehla round hamesha Left → Right hota hai
        return solve(n, true);
    }
};
