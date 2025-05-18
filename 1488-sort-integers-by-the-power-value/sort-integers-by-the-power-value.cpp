class Solution {
public:
    int solveRE(int x) {
    if (x == 1) return 0;
    if (x % 2 == 0)
        return 1 + solveRE(x / 2);
    else
        return 1 + solveRE(3 * x + 1);
    }

    int getKth(int lo, int hi, int k) {
        vector<int> nums;
        for (int i = lo; i <= hi; ++i)
            nums.push_back(i);
        
        // Comparator inside sort using lambda and pure recursion
        sort(nums.begin(), nums.end(), [this](int a, int b) {
            int pa = solveRE(a);
            int pb = solveRE(b);
            if (pa == pb) return a < b;
            return pa < pb;
        });

        return nums[k - 1];
    }
};