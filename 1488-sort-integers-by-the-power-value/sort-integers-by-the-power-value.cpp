class Solution {
public:
    unordered_map<int, int> dp;

    int solveRE(int n) {
    if (n == 1) return 0;
    if (n % 2 == 0)
        return 1 + solveRE(n / 2);
    else
        return 1 + solveRE(3 * n + 1);
    }

    int solveME(int n) {
        if (n == 1) return 0;
        if (dp.count(n)) return dp[n];
        if (n % 2 == 0)
            return dp[n] = 1 + solveME(n / 2);
        else
            return dp[n] = 1 + solveME(3 * n + 1);
    }

    int getKth(int lo, int hi, int k) {
        vector<int> nums;
        for (int i = lo; i <= hi; ++i)
            nums.push_back(i);
        
        // Comparator inside sort using lambda and pure recursion
        sort(nums.begin(), nums.end(), [this](int a, int b) {
            int power_a = solveME(a);
            int power_b = solveME(b);
            if (power_a == power_b) return a < b;
            return power_a < power_b;
        });

        return nums[k - 1];
    }
};