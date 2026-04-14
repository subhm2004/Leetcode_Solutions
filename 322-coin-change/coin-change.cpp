class Solution {
public:

    vector<int> coins;
    vector<int> dp;

    int solve(int amount){

        if(amount==0)
            return 0;

        if(amount<0)
            return 1e9;

        if(dp[amount]!=-1)
            return dp[amount];

        int mini = 1e9;

        for(int coin:coins){

            mini=min(mini,1+solve(amount-coin));
        }

        return dp[amount]=mini;
    }

    int coinChange(vector<int>& c, int amount) {

        coins=c;

        dp.assign(amount+1,-1);

        int ans=solve(amount);

        return ans>=1e9?-1:ans;
    }
};