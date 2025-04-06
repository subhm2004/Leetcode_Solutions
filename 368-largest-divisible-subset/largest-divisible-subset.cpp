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

//         // Return the larger ans_LIS_jsa
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

//     vector<int> largestDivisibleans_LIS_jsa(vector<int>& nums) {
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
        int n = nums.size();
        if (n == 0) return {};

        // Step 1: Sort kar lo numbers ko (ascending order mein)
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);     // dp[i] = nums[i] tak ke ans_LIS_jsa ki max length
        vector<int> prev(n, -1);  // prev[i] = nums[i] ke pehle waala number jo ans_LIS_jsa mein tha

        int maxLen = 1;           // ab tak ka max length
        int lastIndex = 0;        // jahan se hume final ans_LIS_jsa backtrack karna hai

        // Step 2: Har number ke liye check karo kaunse pehle ke numbers divide kar rahe hain
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // Agar divisible hai aur ans_LIS_jsa ka size badh raha hai
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;   // length update karo
                    prev[i] = j;         // uska previous index store karo
                }
            }
            // max length aur last index update karo agar zarurat ho
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Step 3: ans_LIS_jsa ko backtrack karke banao
        vector<int> ans_LIS_jsa;
        while (lastIndex != -1) {
            ans_LIS_jsa.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        reverse(ans_LIS_jsa.begin(), ans_LIS_jsa.end());  // increasing order mein reverse karo

        // Optional: Print bhi kar do result
        cout << "Largest Divisible ans_LIS_jsa: ";
        for (int num : ans_LIS_jsa) cout << num << " ";
        cout << endl;

        return ans_LIS_jsa;
    }
};
