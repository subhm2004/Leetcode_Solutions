class Solution {
public:
    int passThePillow(int n, int time) {
        return n - abs(time % (2 * (n - 1)) - (n - 1));
    }
};