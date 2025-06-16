class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted;
        
        for(int i = 0; i<n; i++) {
            /*
			     Why lower bound ?
				 We want increasing subsequence and  hence 
				 we want to eliminate the duplicates as well.
				 lower_bound returns iterator to "next greater or equal to"
			*/
            auto it = lower_bound(begin(sorted), end(sorted), nums[i]);
            
            if(it == end(sorted))
                sorted.push_back(nums[i]); //greatest : so insert it
            else
                *it = nums[i]; //replace
        }
        
        return (int)sorted.size();
    }
};



// class Solution {
// public:
//     int solveRE(vector<int>& arr, int curr, int parent) {
//         if (curr >= arr.size()) {
//             return 0;
//         }

//         // include
//         int include = 0;
//         if (parent == -1 || arr[curr] > arr[parent])
//             include = 1 + solveRE(arr, curr + 1, curr);

//         // excude
//         int exclude = 0 + solveRE(arr, curr + 1, parent);

//         int ans = max(include, exclude);
//         return ans;
//     }

//     int solveME(vector<int>& arr, int curr, int parent, vector<vector<int>>& dp) {
//         if (curr >= arr.size()) {
//             return 0;
//         }

//         if (dp[curr][parent + 1] != -1)
//             return dp[curr][parent + 1];

//         // include
//         int include = 0;
//         if (parent == -1 || arr[curr] > arr[parent])
//             include = 1 + solveME(arr, curr + 1, curr, dp);

//         // excude
//         int exclude = 0 + solveME(arr, curr + 1, parent, dp);

//         dp[curr][parent + 1] = max(include, exclude);
//         return dp[curr][parent + 1];
//     }

//     int lengthOfans_LIS(vector<int>& nums) {

//         int curr = 0;
//         int parent = -1;
//         // int ans = solveRE(nums, curr, parent );
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return solveME(nums, curr, parent, dp);
//     }
// };

// class Solution {
// public:
//     int lengthOfans_LIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         int max_Length = 1;

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             max_Length = max(max_Length, dp[i]);
//         }

//         return max_Length;
//     }
// };

// class Solution {          // Bottom up easy hi hai 
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;

//         vector<int> dp(n, 1);          // dp[i] = length of ans_LIS ending at i
//         vector<int> parent(n, -1);       // parent[i] = index of previous element in ans_LIS ending at i

//         int max_Length = 1;
//         int last_Index = -1;

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] < nums[i] ) {
//                     dp[i] = max(dp[i] , 1 + dp[j]);
//                     parent[i] = j;
//                 }
//             }
//             max_Length = max(max_Length , dp[i]);
//             last_Index = i;
//         }

//         // Reconstruct the ans_LIS
//         vector<int> ans_LIS;
//         while (last_Index != -1) {
//             ans_LIS.push_back(nums[last_Index]);
//             last_Index = parent[last_Index];
//         }
//         reverse(ans_LIS.begin(), ans_LIS.end());

//         // Print the ans_LIS
//         cout << "Longest Increasing Subsequence: ";
//         for (int num : ans_LIS) {
//             cout << num << " ";
//         }
//         cout << endl;

//         return max_Length;
//     }
// };


