// class Solution {
// public:
//     vector<string> solveRE(int i, int lastGroup, vector<string>& words,
//                            vector<int>& groups) {
//         if (i >= words.size())
//             return {};

//         vector<string> skip = solveRE(i + 1, lastGroup, words, groups);

//         if (groups[i] != lastGroup) {
//             vector<string> take = solveRE(i + 1, groups[i], words, groups);
//             take.insert(take.begin(), words[i]);
//             return (take.size() > skip.size()) ? take : skip;
//         }

//         return skip;
//     }

//     vector<string> solveME(int i, int lastGroup, vector<string>& words,
//                            vector<int>& groups,
//                            vector<vector<vector<string>>>& dp) {
//         if (i >= words.size())
//             return {};

//         if (dp[i][lastGroup + 1].size() > 0)
//             return dp[i][lastGroup + 1];

//         vector<string> skip = solveME(i + 1, lastGroup, words, groups, dp);

//         if (groups[i] != lastGroup) {
//             vector<string> take = solveME(i + 1, groups[i], words, groups, dp);
//             take.insert(take.begin(), words[i]);
//             dp[i][lastGroup + 1] = (take.size() > skip.size()) ? take : skip;
//         } else {
//             dp[i][lastGroup + 1] = skip;
//         }

//         return dp[i][lastGroup + 1];
//     }
//     vector<string> getLongestSubsequence(vector<string>& words,
//                                          vector<int>& groups) {
//         // return solveRE(0, -1, words, groups);

//         vector<vector<vector<string>>> dp(words.size(),
//         vector<vector<string>>(groups.size() + 1)); 
//         return solveME(0, -1, words, groups, dp);
//     }
// };
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<string> result;
        for(int i = 0; i < n; i++) {
            if(i == 0 || groups[i] != groups[i-1]) { //new group started, so pick the first element
                result.push_back(words[i]);
            }
        }

        return result;
    }
};