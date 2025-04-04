// class Solution {             //LIS form
// public:
//     int solveRE(int i, int prev, vector<int>& arr, int& diff) {
//         // Agar i array ke size se bada ho jaye, toh return 0 (Base case)
//         if (i >= arr.size()) {
//             return 0;
//         }

//         int include = 0;

//         // Agar prev -1 hai (matlab pehla element hai) ya phir difference match
//         // kar raha hai
//         if (prev == -1 || arr[i] - arr[prev] == diff) {
//             // Current element ko include karke recursion call karte hain
//             include = 1 + solveRE(i + 1, i, arr, diff);
//         }

//         // Current element ko exclude karke recursion call karte hain
//         int exclude = solveRE(i + 1, prev, arr, diff);

//         // Dono cases ka maximum return karte hain
//         return max(include, exclude);
//     }

//     int solveME(int i, int prev, vector<int>& arr, int& diff,
//                 unordered_map<string, int>& dp) {
//         if (i >= arr.size()) {
//             return 0;
//         }

//         string key = to_string(i) + "_" + to_string(prev);
//         if (dp.find(key) != dp.end()) {
//             return dp[key];
//         }

//         int include = 0;
//         if (prev == -1 || arr[i] - arr[prev] == diff) {
//             include = 1 + solveME(i + 1, i, arr, diff, dp);
//         }

//         int exclude = solveME(i + 1, prev, arr, diff, dp);

//         return dp[key] = max(include, exclude);
//     }

//     int longestSubsequence(vector<int>& arr, int difference) {
//         unordered_map<string, int> dp;

//         return solveME(0, -1, arr, difference, dp);
//     }
// };


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int max_length = 1;

        for (int num : arr) {
            dp[num] = dp[num - difference] + 1;
            max_length = max(max_length, dp[num]);
        }

        return max_length;
    }
};
