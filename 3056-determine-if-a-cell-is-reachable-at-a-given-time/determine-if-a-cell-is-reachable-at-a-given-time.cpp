class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int minStep = max(abs(sx - fx), abs(sy - fy)); // Chebyshev distance
        return minStep == 0 ? t != 1 : minStep <= t;
    }
};