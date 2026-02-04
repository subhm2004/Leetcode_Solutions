class Solution {
public:
    int dp[1001][1001];
    int solve(int curr_a_count, int clip_a, int n) {
        if(curr_a_count == n) {
            return 0;
        }

        if(curr_a_count > n) {
            return 10000;
        }


        if(dp[curr_a_count][clip_a] != -1) {
            return dp[curr_a_count][clip_a];
        }

        int copy_then_paste = 1 + 1 + solve(curr_a_count + curr_a_count, curr_a_count, n);

        int paste     = 1 + solve(curr_a_count + clip_a, clip_a, n);

        return dp[curr_a_count][clip_a] = min(copy_then_paste, paste);
    }

    int minSteps(int n) {
        if(n == 1)
            return 0; //We already have 1 A
        
        memset(dp, -1, sizeof(dp));

        //We have to start with a copy, hence 1 + 
        return 1 + solve(1, 1, n);
    }
};