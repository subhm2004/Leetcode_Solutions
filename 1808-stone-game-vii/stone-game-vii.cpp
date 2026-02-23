class Solution {
public:
    int dp[1005][1005];
    vector<int> prefix;

    int range_sum(int l,int r){
        return prefix[r+1]-prefix[l];
    }

    int solve(int l,int r){
        if(l==r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int left_gain  = range_sum(l+1,r) - solve(l+1,r);
        int right_gain = range_sum(l,r-1) - solve(l,r-1);

        return dp[l][r] = max(left_gain ,right_gain);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        prefix.assign(n+1,0);
        for(int i=0;i<n;i++)
            prefix[i+1]=prefix[i]+stones[i];

        memset(dp,-1,sizeof(dp));

        return solve(0,n-1);
    }
};