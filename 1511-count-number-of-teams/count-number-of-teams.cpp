// https://www.youtube.com/watch?v=UZupIKXnzq8

class Solution {  
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        for (int j = 1; j < n - 1; ++j) {
            int left_Smaller = 0, left_Greater = 0;
            int right_Smaller = 0, right_Greater = 0;

            // Count for left side
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) left_Smaller++;
                else if (rating[i] > rating[j]) left_Greater++;
            }

            // Count for right side
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] > rating[j]) right_Greater++;
                else if (rating[k] < rating[j]) right_Smaller++;
            }

            count += left_Smaller * right_Greater + left_Greater * right_Smaller;
        }

        return count;
    }
};


// class Solution {
//     public:

//    int solveRE(int i, int prev, int count, bool increasing, vector<int>& rating, int n) {
//         if (count == 3) return 1;  // team of size 3 formed
//         if (i == n) return 0;    // reached end without forming team

//         int ans = 0;

//         // Option 1: pick current soldier if valid
//         if (prev == -1 ||
//             (increasing && rating[i] > rating[prev]) ||
//             (!increasing && rating[i] < rating[prev])) {
//             ans += solveRE(i + 1, i, count + 1, increasing, rating, n);
//         }
//         // Option 2: skip current soldier
//         ans += solveRE(i + 1, prev, count, increasing, rating, n);

//         return ans;
//     }

//     int solveME(int i, int prev, int count, bool increasing, vector<int>& rating, int n, vector<vector<vector<vector<int>>>> &dp) {
//         if (count == 3) return 1;  
//         if (i == n) return 0;      

//         if (dp[i][prev + 1][count][increasing] != -1)
//             return dp[i][prev + 1][count][increasing];

//         int ans = 0;

//         // Option 1: pick current soldier if valid
//         if (prev == -1 ||
//             (increasing && rating[i] > rating[prev]) ||
//             (!increasing && rating[i] < rating[prev])) {
//             ans += solveME(i + 1, i, count + 1, increasing, rating, n, dp);
//         }
//         // Option 2: skip current soldier
//         ans += solveME(i + 1, prev, count, increasing, rating, n, dp);

//         return dp[i][prev + 1][count][increasing] = ans;
//     }

//     int numTeams(vector<int>& rating) {
//         int n = rating.size();

//         // dp dimensions: i in [0..n], prev in [-1..n-1] mapped to [0..n], count in [0..3], increasing in [0..1]
//         vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(4, vector<int>(2, -1))));

//         int increasing_Teams = solveME(0, -1, 0, true, rating, n, dp);
//         int decreasing_Teams = solveME(0, -1, 0, false, rating, n, dp);

//         return increasing_Teams + decreasing_Teams;
//     }
// };
