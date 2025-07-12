class Solution {
public:
    const int MOD = 1e9 + 7;

    int binary_Expo_Iterative(int a, int b) {
        int result = 1;
        a %= MOD;

        while (b > 0) {
            if (b & 1) {
                result = (1LL * result * a) % MOD;
            }
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }

        return result;
    }

    int monkeyMove(int n) {
        // ya to same bandar anti-clock direction me jayea ya to clockwise
        // direction me jayega ye do case hi h jab safe state aayegi or koi
        // collosion nhi hoga
        int total_ways = binary_Expo_Iterative(2, n) - 2;
        return (total_ways + MOD) % MOD;
    }
};
