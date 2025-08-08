class Solution {
public:
    double solveRE(int A, int B) {
        // Base case: Both soups finished at same time
        if (A <= 0 && B <= 0)
            return 0.5;

        // Base case: Soup A finished first (what we want)
        if (A <= 0)
            return 1.0;

        // Base case: Soup B finished first
        if (B <= 0)
            return 0.0;

        double probability = 0.0;

        // Option 1: Serve 100ml of A, 0ml of B
        probability += 0.25 * solveRE(A - 100, B);

        // Option 2: Serve 75ml of A, 25ml of B
        probability += 0.25 * solveRE(A - 75, B - 25);

        // Option 3: Serve 50ml of A, 50ml of B
        probability += 0.25 * solveRE(A - 50, B - 50);

        // Option 4: Serve 25ml of A, 75ml of B
        probability += 0.25 * solveRE(A - 25, B - 75);

        return probability;
    }

    double solveME(int A, int B, vector<vector<double>>& dp) {
        if(A <= 0 && B <= 0)
            return 0.5;
        
        if(A <= 0)
            return 1.0;
        if(B <= 0)
            return 0.0;
        
        if(dp[A][B] != -1.0)
            return dp[A][B];
        
        vector<pair<int, int>> serves = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};

        double probability = 0.0;
        
         for(auto& [A_serve, B_serve] : serves) {
            probability += 0.25 * solveME(A - A_serve, B - B_serve, dp);
        }
        
        return dp[A][B] = probability;
    }

    double soupServings(int n) {
        // return solveRE(n, n); 
        if (n >= 5000) {
            return 1.0;
        }

        vector<vector<double>> dp(n+1, vector<double>(n+1, -1.0));
        return solveME(n, n, dp);

}
};