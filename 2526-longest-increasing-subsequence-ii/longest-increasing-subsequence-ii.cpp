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
    SegmentTree(int maxVal) {
        size = maxVal + 1;
        segTree.resize(4 * size, 0);
    }

    //  max value in range [ql, qr] (Range Query Maximum)
    int query(int i, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0; // completely outside
        if (ql <= l && r <= qr) return segTree[i]; // completely inside

        // partial overlap
        int mid = (l + r) / 2;
        return max(
            query(2 * i + 1, l, mid, ql, qr),
            query(2 * i + 2, mid + 1, r, ql, qr)
        );
    }

    // update index `idx` to max(val, current value)
    void update(int i, int l, int r, int idx, int val) {
        if (l == r) {
            segTree[i] = max(segTree[i], val);
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * i + 1, l, mid, idx, val);
        else
            update(2 * i + 2, mid + 1, r, idx, val);

        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    // range query
    int query_Range(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    // point update
    void update_Index(int idx, int val) {
        update(0, 0, size - 1, idx, val);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());

        SegmentTree* segTree = new SegmentTree(maxNum);  
        int max_Len = 1;
        for (int num : nums) {
            // Step 1: Get max value from [num - k, num - 1]
            int best = segTree->query_Range(num - k, num - 1);

            // Step 2: current dp length
            int curr_Len = best + 1;

            // Step 3: Update tree at num
            segTree->update_Index(num, curr_Len);

            // Step 4: update answer
            max_Len = max(max_Len, curr_Len);
        }

        delete segTree; //  Memory cleanup
        return max_Len;
    }
};
