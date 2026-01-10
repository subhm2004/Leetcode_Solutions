// class Solution {
// public:
//     // Recursive
//     int solveRE(vector<int>& arr, int curr, int prev, int k) {
//         if (curr >= arr.size()) {
//             return 0;
//         }

//         int include = 0;
//         if (prev == -1 || (arr[curr] > arr[prev] && arr[curr] - arr[prev] <= k)) {
//             include = 1 + solveRE(arr, curr + 1, curr, k);
//         }

//         int exclude = solveRE(arr, curr + 1, prev, k);

//         return max(include, exclude);
//     }

//     // Memoized
//     int solveME(vector<int>& arr, int curr, int prev, int k, vector<vector<int>>& dp) {
//         if (curr >= arr.size()) {
//             return 0;
//         }

//         if (dp[curr][prev + 1] != -1)
//             return dp[curr][prev + 1];

//         int include = 0;
//         if (prev == -1 || (arr[curr] > arr[prev] && arr[curr] - arr[prev] <= k)) {
//             include = 1 + solveME(arr, curr + 1, curr, k, dp);
//         }

//         int exclude = solveME(arr, curr + 1, prev, k, dp);

//         dp[curr][prev + 1] = max(include, exclude);
//         return dp[curr][prev + 1];
//     }

//     // Bottom-up DP
//     int solve_Bottom_Up(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> dp(n, 1); // dp[i] = length of LIS ending at i
//         int maxLength = 1;

//         for (int i = 1; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (nums[j] < nums[i] && nums[i] - nums[j] <= k) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             maxLength = max(maxLength, dp[i]);
//         }

//         return maxLength;
//     }

//     int lengthOfLIS(vector<int>& nums, int k) {
//         int n = nums.size();
//         // return solveRE(nums, 0, -1, k); 
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return solveME(nums, 0, -1, k, dp); 

//         // return solve_Bottom_Up(nums, k); 

//     }
// };



class SegmentTree {     
    vector<int> segTree;     
    int size;  
    
public:     
    // Constructor: maxVal tak ke liye segment tree banate hai
    SegmentTree(int maxVal) {         
        size = maxVal + 1;         
        segTree.resize(4 * size, 0);  // 4*size space chahiye segment tree ke liye
    }      

    // Range Query Maximum: [ql, qr] range mein maximum value nikalta hai
    int query(int i, int l, int r, int ql, int qr) {         
        // Agar query range bilkul bahar hai current node range se
        if (qr < l || r < ql) return 0; // completely outside         
        
        // Agar current node range pura query range ke andar hai
        if (ql <= l && r <= qr) return segTree[i]; // completely inside          

        // Partial overlap: kuch part andar hai, kuch bahar
        int mid = (l + r) / 2;         
        return max(             
            query(2 * i + 1, l, mid, ql, qr),        // Left child se query
            query(2 * i + 2, mid + 1, r, ql, qr)     // Right child se query
        );     
    }      

    // Point Update: index `idx` ko max(current_value, new_val) se update karta hai
    void update(int i, int l, int r, int idx, int val) {         
        // Agar leaf node hai (l == r), directly update kar do
        if (l == r) {             
            segTree[i] = max(segTree[i], val);  // Maximum le ke update karo
            return;         
        }          

        int mid = (l + r) / 2;         
        // Decide karo ki left subtree mein jana hai ya right mein
        if (idx <= mid)             
            update(2 * i + 1, l, mid, idx, val);      // Left child update
        else             
            update(2 * i + 2, mid + 1, r, idx, val);  // Right child update          

        // Current node ko update karo using child nodes ka maximum
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);     
    }      

    // Public wrapper function: range query ke liye
    int query_Range(int l, int r) {         
        return query(0, 0, size - 1, l, r);     
    }      

    // Public wrapper function: point update ke liye
    void update_Index(int idx, int val) {         
        update(0, 0, size - 1, idx, val);     
    } 
};  

class Solution { 
public:     
    // Main function: Longest Increasing Subsequence with constraint
    // nums array mein LIS find karna hai jahan consecutive elements ka diff <= k ho
    int lengthOfLIS(vector<int>& nums, int k) {         
        // Sabse bada number find karo array mein
        int maxNum = *max_element(nums.begin(), nums.end());          

        // Segment tree banao maxNum size ka
        SegmentTree* segTree = new SegmentTree(maxNum);           

        int max_Len = 1;  // Answer variable (minimum length 1 hogi)
        
        // Har number ke liye process karo
        for (int num : nums) {             
            // Step 1: Range [num-k, num-1] mein maximum LIS length find karo
            // DETAILED EXPLANATION: Ye range kyun li?
            // 1. Hum current 'num' ke pehle wale valid numbers dhund rahe hai
            // 2. Valid matlab: prev_num < current_num (increasing subsequence)
            // 3. Constraint: current_num - prev_num <= k
            // 4. Rearrange: prev_num >= current_num - k
            // 5. Combining: current_num - k <= prev_num < current_num
            // 6. Range ban gaya: [num-k, num-1] (num-1 tak kyunki num khud included nahi)
            // 7. Example: num=7, k=3 → valid previous numbers: 4,5,6 → range [4,6]
            int best = segTree->query_Range(num - k, num - 1);              

            // Step 2: Current number ke liye LIS length calculate karo
            // Previous best length + 1 (current number add kar rahe hai)
            int curr_Len = best + 1;              

            // Step 3: Segment tree mein current number ki position update karo
            // Agar pehle se koi value hai toh maximum le lo
            segTree->update_Index(num, curr_Len);              

            // Step 4: Overall answer update karo
            max_Len = max(max_Len, curr_Len);         
        }          

        delete segTree; // Memory cleanup - dynamic allocation ka safai
        return max_Len;     
    } 
};

/*
ALGORITHM EXPLANATION (Hinglish):

1. PROBLEM SAMJHO:
   - Normal LIS mein hum increasing subsequence chahte hai
   - Yahan constraint hai: arr[j] - arr[i] <= k (where j > i)
   - Matlab consecutive elements ka difference k se zyada nahi hona chahiye

2. APPROACH:
   - Dynamic Programming + Segment Tree use karte hai
   - dp[i] = ending at index i, maximum LIS length
   - Har number ke liye: current number se k distance tak ke previous numbers check karo
   - Unme se maximum LIS length lo aur current ke liye +1 kar do

3. SEGMENT TREE KYUN?
   - Range [num-k, num-1] mein maximum efficiently find karna hai
   - Naive approach O(n²) hoga, segment tree se O(n log maxVal) hoga
   - Values ko index ke roop mein use kar rahe hai (coordinate compression)

4. COMPLEXITY:
   - Time: O(n log maxVal) where n = array size
   - Space: O(maxVal) for segment tree

5. EXAMPLE:
   nums = [4,2,1,4,3,4,5,8,15], k = 3
   - 4: range [1,3] check -> 0, dp[4] = 1
   - 2: range [-1,1] check -> 0, dp[2] = 1  
   - 1: range [-2,0] check -> 0, dp[1] = 1
   - 4: range [1,3] check -> max(dp[2],dp[1]) = 1, dp[4] = 2
   - Aur aise continue...
*/