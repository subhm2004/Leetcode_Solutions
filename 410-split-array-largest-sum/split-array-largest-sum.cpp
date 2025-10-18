// class Solution { // partition dp
// public:
//     // Recursive function: solveRE(i, k) -> first i elements ko k partitions me split karna
//     // aur largest sum minimize karna
//     long solveRE(int i, int k, const vector<long>& prefix, vector<vector<long>>& dp) {
//         if (k == 1) {
//             // Base case: sirf 1 partition left hai
//             // Toh first i elements ka sum hi answer hai
//             return prefix[i];
//         }

//         if (dp[i][k] != -1) return dp[i][k]; // Agar pehle se calculate ho chuka hai, directly return karo

//         long result = LONG_MAX;

//         // Loop for last partition split
//         // j = end index of first k-1 partitions
//         // Important: j = k-1 se start karte hain kyunki
//         // agar j < k-1, to first j elements me k-1 partitions nahi bana sakte
//         // Har partition me kam se kam 1 element hona chahiye
//         // Ending point naturally i-1 hai, kyunki last partition me kam se kam 1 element chahiye
//         for (int j = k - 1; j < i; ++j) {
//             long left = solveRE(j, k - 1, prefix, dp);      // Max sum of first k-1 partitions
//             long right = prefix[i] - prefix[j];            // Sum of last partition
//             result = min(result, max(left, right));        // Minimize the largest sum
//         }

//         return dp[i][k] = result;  
//     }

//     int splitArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<long> prefix(n + 1, 0);

//         // Prefix sums compute karte hain for fast subarray sum queries
//         for (int i = 0; i < n; ++i) {
//             prefix[i + 1] = prefix[i] + nums[i];
//         }

//         // dp[i][k] stores minimum largest sum for first i elements split into k parts
//         vector<vector<long>> dp(n + 1, vector<long>(k + 1, -1));

//         return solveRE(n, k, prefix, dp); // Start recursion with all n elements and k partitions
//     }
// };



//================================================
//Binary Search Solution 
class Solution {
public:
    bool can_split(const vector<int>& nums, int k, long max_sum) {
    int splits = 1;       // Pehli subarray start kar di
    long curr_sum = 0;    // Current subarray sum

    for (int num : nums) {
        if (curr_sum + num > max_sum) {
            splits++;       // New subarray start karo
            curr_sum = num; // Naya subarray me current number add karo
            if (splits > k) return false; // k se zyada subarrays ban gaye → impossible
        } else {
            curr_sum += num; // Current subarray me add karo
        }
    }

    return true; // k ya kam subarrays me split possible
}


    int splitArray(vector<int>& nums, int k) {
        long left = *max_element(nums.begin(), nums.end());
        long right = accumulate(nums.begin(), nums.end(), 0L);
        int ans;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (can_split(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};





