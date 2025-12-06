// // Partition DP Solution
// class Solution {
// public:
//     const int MOD = 1e9 + 7;

//     int solveRE(vector<int>& nums, int i, int k) {
//         int n = nums.size();
//         if (i >= n)
//             return 1; // reached end, valid partition

//         long long ans = 0;
//         int max_val = nums[i];
//         int min_val = nums[i];

//         // expand segment starting at idx i
//         for (int j = i; j < n; j++) {
//             max_val = max(max_val, nums[j]);
//             min_val = min(min_val, nums[j]);

//             if (max_val - min_val > k)
//                 break; // cannot extend segment

//             ans = (ans + solveRE(nums, j + 1, k)) % MOD;
//         }

//         return ans;
//     }
//     /*
//     Explanation of j = i in loop agar mne function me i pass kiya hai to :

//     - j = i  => segment = nums[i..j] = nums[i..i] = [nums[i]]
//                 // minimum size 1 segment included
//     - j = i+1 => segment = nums[i+1..j] = nums[i+1..i+1] = [nums[i+1]]
//                 // nums[i] skip ho gaya, galat result
//     - Isliye hamesha j = i se start karna chahiye
//     */

//     int solveME(vector<int>& nums, int i, int k, vector<int>& dp) {
//         int n = nums.size();
//         if (i >= n) return 1;  

//         if (dp[i] != -1) return dp[i];  

//         long long ans = 0;
//         int max_val = nums[i];
//         int min_val = nums[i];

//          for (int j = i; j < n; j++) {
//             max_val = max(max_val, nums[j]);
//             min_val = min(min_val, nums[j]);

//             if (max_val - min_val > k)
//                 break;  

//             ans = (ans + solveME(nums, j + 1, k, dp)) % MOD;
//         }

//         return dp[i] = ans;  
//     }


//     int countPartitions(vector<int>& nums, int k) {        
//         int n = nums.size();
//         // return solveRE(nums, 0, k);
//         vector<int> dp(n, -1); 
//         return solveME(nums, 0, k, dp);
//     }
// };

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<int> dp(n + 1, 0);
        vector<int> pref(n + 1, 0);

        dp[0] = 1;
        pref[0] = 1;

        deque<int> minQ, maxQ;
        int i = 0, j = 0;

        while (j < n) {

            while (!maxQ.empty() && nums[j] > nums[maxQ.back()])
                maxQ.pop_back();
            maxQ.push_back(j);

            while (!minQ.empty() && nums[j] < nums[minQ.back()])
                minQ.pop_back();
            minQ.push_back(j);

            while (nums[maxQ.front()] - nums[minQ.front()] > k) {
                i++;
                if (!maxQ.empty() && maxQ.front() < i) maxQ.pop_front();
                if (!minQ.empty() && minQ.front() < i) minQ.pop_front();
            }

            dp[j + 1] = (pref[j] - (i > 0 ? pref[i - 1] : 0) + MOD) % MOD;
            pref[j + 1] = (pref[j] + dp[j + 1]) % MOD;

            j++;
        }

        return dp[n];
    }
};
