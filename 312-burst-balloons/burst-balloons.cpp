class Solution {
public:
    int solveRE(vector<int>& nums, int start, int end) {
        // Base case: Agar start > end hai, matlab koi balloon nahi bacha burst karne ke liye
        // is range mein, toh 0 coins return karo
        if (start > end)
            return 0;
        
        // coins ko minimum value se initialize karo taaki maximum coins track kar sakein
        int coins = INT_MIN;
        
        // Har balloon 'i' ko range [start, end] mein LAST balloon ke roop mein burst karne ka try karo
        // Key insight: Hum har balloon ko last wala consider karte hain jo burst hoga
        // Isse ensure hota hai ki jab balloon 'i' burst hoga, uske neighbors honge
        // nums[start-1] aur nums[end+1] (boundary balloons)
        for (int i = start; i <= end; i++) {
            
            // Balloon 'i' ko last balloon ke roop mein burst karne se kitne coins milenge:
            // - nums[start-1]: Left boundary balloon (exist karega jab 'i' last mein burst hoga)
            // - nums[i]: Current balloon jo burst ho raha hai
            // - nums[end+1]: Right boundary balloon (exist karega jab 'i' last mein burst hoga)
            
            // Current balloon 'i' ko last mein burst karne se milne wale coins
            int current_Coins = nums[start - 1] * nums[i] * nums[end + 1];
            
            // Left subproblem: start se i-1 tak ke sabhi balloons burst karo recursively
            // Ye balloons balloon 'i' se pehle burst honge
            int left_Subproblem = solveRE(nums, start, i - 1);
            
            // Right subproblem: i+1 se end tak ke sabhi balloons burst karo recursively
            // Ye balloons bhi balloon 'i' se pehle burst honge
            int right_Subproblem = solveRE(nums, i + 1, end);
            
            // Total coins = current balloon ke coins + left subproblem + right subproblem
            int totalCoins = current_Coins + left_Subproblem + right_Subproblem;
            
            // Maximum coins ka track rakho
            coins = max(coins, totalCoins);
        }
        
        // Range [start, end] se maximum kitne coins mil sakte hain return karo
        return coins;
    }
    
    int solveME(vector<int>& nums, int start, int end,
                vector<vector<int>>& dp) {
        if (start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int coins = INT_MIN;
        for (int i = start; i <= end; i++) {
            coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] +
                                   solveME(nums, start, i - 1, dp) +
                                   solveME(nums, i + 1, end, dp));
        }
        return dp[start][end] = coins;
    }
     
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solveME(nums, 1, n - 2, dp);
    }
};