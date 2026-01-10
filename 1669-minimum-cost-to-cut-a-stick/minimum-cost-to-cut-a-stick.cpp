// https://www.youtube.com/watch?v=x4cRwVEFwHc
class Solution {
public:
    vector<vector<int>> dp;

    int solveRE(vector<int>& cuts, int i, int j) {
        // Base case: agar koi cut possible hi nahi
        if (j - i <= 1) return 0;

        int min_cost = INT_MAX;

        // i aur j ke beech wale har possible cut position try karo kyoki i or j pr to scale ki values hai or cuts ki postion start hoti h i+1 se j-1 tak 
        for (int k = i + 1; k < j; k++) {
            int cost = cuts[j] - cuts[i]; // current stick ka length
            int total_cost = /* Left scale */solveME(cuts, i, k) + /* Right scale */solveME(cuts, k, j) + cost;
            min_cost = min(min_cost, total_cost);
        }

        return min_cost;
    }

    int solveME(vector<int>& cuts, int i, int j) {
         if (j - i <= 1) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int min_cost = INT_MAX;

        for (int k = i + 1; k < j; ++k) {
            int cost = cuts[j] - cuts[i]; 
            int total_cost = solveME(cuts, i, k) + solveME(cuts, k, j) + cost;
            min_cost = min(min_cost, total_cost);
        }

        return dp[i][j] = min_cost;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        dp.assign(m+2, vector<int>(m+2, -1)); 

        return solveME(cuts, 0, m - 1);
    }
};
