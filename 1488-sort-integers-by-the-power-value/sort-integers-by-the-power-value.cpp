class Solution {
public:
    unordered_map<int, int> dp;

    int solveRE(int x) {
    if (x == 1) return 0;
    if (x % 2 == 0)
        return 1 + solveRE(x / 2);
    else
        return 1 + solveRE(3 * x + 1);
    }

    int solveME(int x) {
        if (x == 1) return 0;
        if (dp.count(x)) return dp[x];
        if (x % 2 == 0)
            return dp[x] = 1 + solveME(x / 2);
        else
            return dp[x] = 1 + solveME(3 * x + 1);
    }
    
    int getKth(int lo, int hi, int k) {
        vector<int> nums;
        for (int i = lo; i <= hi; ++i)
            nums.push_back(i);
        
        // Comparator inside sort using lambda and pure recursion
        sort(nums.begin(), nums.end(), [this](int a, int b) {
            int pa = solveME(a);
            int pb = solveME(b);
            if (pa == pb) return a < b;
            return pa < pb;
        });

        return nums[k - 1];
    }
};