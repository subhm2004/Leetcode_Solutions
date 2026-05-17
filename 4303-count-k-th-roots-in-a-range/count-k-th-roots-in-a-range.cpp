class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int right = floor(pow(r, 1.0 / k) + 1e-9);
        int left = ceil(pow(l, 1.0 / k) - 1e-9);
        return max(0, right - left + 1);
    }
};