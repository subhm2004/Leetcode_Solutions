class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        if (target == 0) return true;
        return target % __gcd(x, y) == 0;
    }
};