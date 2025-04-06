// class Solution {            // LIS varient hai ye
// public:
//     vector<int> solveRE(int i, vector<int>& nums, int prev) {
//         if (i >= nums.size())
//             return {}; // Base Case

//        // **Include Case:** If it's the first element OR it is divisible by the
//         // previous element
//         vector<int> include;
//         if (prev == -1 || nums[i] % nums[prev] == 0) {
//             include = solveRE(i + 1, nums, i);
//             include.push_back(nums[i]); // Add current element
//         }

//          // **Exclude Case:** Skip current element
//         vector<int> exclude = solveRE(i + 1, nums, prev);

//         // Return the larger subset
//         return (include.size() > exclude.size()) ? include : exclude;
//     }

//     vector<int> solveME(int i, vector<int>& nums, int prev,
//                         unordered_map<string, vector<int>>& dp) {
//         if (i >= nums.size())
//             return {};

//         string key = to_string(i) + "_" + to_string(prev);
//         if (dp.count(key))
//             return dp[key];

//         vector<int> include;
//         if (prev == -1 || nums[i] % nums[prev] == 0) {
//             include = solveME(i + 1, nums, i, dp);
//             include.push_back(nums[i]);
//         }

//         vector<int> exclude = solveME(i + 1, nums, prev, dp);

//          return dp[key] = (include.size() > exclude.size()) ? include : exclude;
//     }

//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end()); // Sorting ensures divisibility order
//         unordered_map<string, vector<int>>dp; 
//         vector<int> result = solveME(0, nums, -1, dp);
//         reverse(result.begin(), result.end()); // Maintain correct order
//         return result;
//     }
// };

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> dp(n, 1);         // dp[i] = size of largest subset ending at i
        vector<int> prev(n, -1);      // to backtrack and build result

        int maxLen = 1;
        int maxIdx = 0;

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

            if(dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        // Reconstruct the result
        vector<int> result;
        while(maxIdx >= 0) {
            result.push_back(nums[maxIdx]);
            maxIdx = prev[maxIdx];
        }

        reverse(result.begin(), result.end());  // to maintain increasing order
        return result;
    }
};
