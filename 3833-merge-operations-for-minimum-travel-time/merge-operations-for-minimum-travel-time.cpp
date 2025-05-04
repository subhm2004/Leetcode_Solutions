class Solution {
public:
    int solveRE(int i, int k, int currRate,vector<int>& position,vector<int>& time, int n) {
        if (i == n - 1) {
            if (k > 0) return INT_MAX;
            return 0;
        }

        int ans = INT_MAX;

        // Option 1: Skip and no merge
        int skipTime = solveRE(i + 1, k, time[i + 1], position, time, n);
        if (skipTime != INT_MAX) {
            int dist = position[i + 1] - position[i];
            ans = min(ans, dist * currRate + skipTime);
        }

        // Option 2: Merge next stops
        if (k > 0) {
            int mergeTime = time[i + 1];
            int mergeCount = 0;


            //i ---- i+1 ------ i+2 ------- i+3 .....
            //If we merge i+1 and i+2
            //i ---------- i+2 -------- i+3 , then you see (i+1) disappeared and 1 merge required

            //What if we want i -------- i+3 ???
            //We will need 2 merges i.e. merge i+1 to i+2 and i+2 to i+3, meaning we need two merges
            // i ------ i+3 .......

            //This for loop does that. It first tries to connect i to i+2, then i+3 and so on and
            //keeps checking how many merges required and also keep calculating the time required to find minimum

            for (int j = i + 2; j < n && mergeCount < k; j++) {
                mergeCount++;
                mergeTime += time[j];

                int mergedans = solveRE(j, k - mergeCount, mergeTime, position, time, n);
                if (mergedans != INT_MAX) {
                    int dist = position[j] - position[i];
                    ans = min(ans, dist * currRate + mergedans);
                }
            }
        }

        return ans;
    }
    
    int solveME(int i, int k, int currRate, vector<int>& position, vector<int>& time, int n, vector<vector<vector<int>>>& dp) {
        if (i == n - 1) {
            return (k > 0) ? INT_MAX : 0;
        }

        if (dp[i][k][currRate] != -1) return dp[i][k][currRate];

        int ans = INT_MAX;

        // Option 1: Skip and no merge
        int skipTime = solveME(i + 1, k, time[i + 1], position, time, n, dp);
        if (skipTime != INT_MAX) {
            int dist = position[i + 1] - position[i];
            ans = min(ans, dist * currRate + skipTime);
        }

        // Option 2: Merge next stops
        if (k > 0) {
            int mergeTime = time[i + 1];
            int mergeCount = 0;

            for (int j = i + 2; j < n && mergeCount < k; j++) {
                mergeCount++;
                mergeTime += time[j];

                int mergedans = solveME(j, k - mergeCount, mergeTime, position, time, n, dp);
                if (mergedans != INT_MAX) {
                    int dist = position[j] - position[i];
                    ans = min(ans, dist * currRate + mergedans);
                }
            }
        }

        return dp[i][k][currRate] = ans;
    }

    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        // return solveRE(0, k, time[0], position, time, n);
        int maxTimeSum = accumulate(time.begin(), time.end(), 0);

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(maxTimeSum + 1, -1)));

        return solveME(0, k, time[0], position, time, n, dp);
    }
};
