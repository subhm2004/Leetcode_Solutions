class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);  // Difference array to manage range updates
        int sum = 0, k = 0;

        for (int i = 0; i < n; i++) {
            // Ensure sum at index `i` is at least `nums[i]`
            while (sum + diff[i] < nums[i]) {
                if (k >= queries.size()) return -1;  // Not enough queries to satisfy condition

                // Extract query details
                int l = queries[k][0], r = queries[k][1], val = queries[k][2];
                k++;  // Move to the next query

                // Apply the query only if it affects index `i`
                if (r >= i) {
                    diff[max(l, i)] += val;
                    diff[r + 1] -= val;
                }
            }
            sum += diff[i];  // Update sum for the next iteration
        }
        return k;  // Return the number of queries used
    }
};


// class Solution {
// public:
//     bool isZeroArray(vector<int>& nums) {
//         return all_of(nums.begin(), nums.end(), [](int x) { return x == 0; });
//     }

//     bool canMakeZeroRecursive(vector<int>& nums, 
//                             vector<vector<int>>& queries, 
//                               int k, vector<int>& diff, int i) {
//         if (i == k) {
//             int total = 0;
//             for (int j = 0; j < nums.size(); ++j) {
//                 total += diff[j];
//                 if (total < nums[j]) return false;
//             }
//             return true;
//         }

//         int l = queries[i][0], r = queries[i][1], val = queries[i][2];
//         diff[l] += val;
//         if (r + 1 < nums.size()) diff[r + 1] -= val;

//         return canMakeZeroRecursive(nums, queries, k, diff, i + 1);
//     }

//     bool canMakeZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
//         vector<int> diff(nums.size() + 1, 0);
//         return canMakeZeroRecursive(nums, queries, k, diff, 0);
//     }

//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         if (isZeroArray(nums)) return 0;

//         int left = 1, right = queries.size(), ans = -1;
//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (canMakeZero(nums, queries, mid)) {
//                 ans = mid;
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         }
//         return ans;
//     }
// };
