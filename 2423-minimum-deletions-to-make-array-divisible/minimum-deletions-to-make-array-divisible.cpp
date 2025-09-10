class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        // nums ko set me daalo → sorted unique elements
        set<int> s(nums.begin(), nums.end());

        int deletions = 0;
        for (int candidate : s) {
            bool ok = true;
            for (int x : numsDivide) {
                if (x % candidate != 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                // jitne nums < candidate h unko delete karna padega
                for (int val : nums) {
                    if (val < candidate) deletions++;
                }
                return deletions;
            }
        }
        return -1;
    }
};
