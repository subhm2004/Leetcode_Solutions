typedef long long ll;
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (ll k = 0; k <= 60; k++) {
            ll target = (ll)num1 - k * (ll)num2;
            if (target < 0)
                continue;

            int bits = __builtin_popcountll(target); // kisi bhi number ki binary representatin me kitni set bits hai ( set bits hoti h 1 kitne present h uski binary representatin me ) okay ?

            if (bits <= k && k<= target) 
                return (int)k;
        }
        return -1;
    }
};