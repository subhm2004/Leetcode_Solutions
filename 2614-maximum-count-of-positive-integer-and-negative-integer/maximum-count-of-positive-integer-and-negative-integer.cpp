class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i : nums) {
            if (i > 0) {
                ++a;
            } else if (i < 0) {
                ++b;
            }
        }
        return max(a, b);
    }
};