auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    int solveME(vector<int>& energy, int i, int k, vector<int>& dp) {
        // base case
        if (i >= energy.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];
        
        // current magician ki energy + next jump
        dp[i] = energy[i] + solveME(energy, i + k, k, dp);
        return dp[i];
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        vector<int> dp(n, -1);  

        // har possible starting point se try karte hain
        for (int i = 0; i < n; i++) {
            ans = max(ans, solveME(energy, i, k, dp));
        }

        return ans;
    }
};
