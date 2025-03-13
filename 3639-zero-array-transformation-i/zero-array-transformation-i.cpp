class Solution {
public:
   
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);  // Difference array for range updates
        int sum = 0, k = 0;  

        for (int i = 0; i < n; i++) {
            while (sum + diff[i] < nums[i]) {
                if (k >= queries.size()) return false;  // Not enough queries to make nums[i] zero

                // Extract query details
                int l = queries[k][0], r = queries[k][1], val = 1;  // Decrease by `1`
                k++;  // Move to the next query

                // Apply the query only if it affects index `i`
                if (r >= i) {
                    diff[max(l, i)] += val;
                    diff[r + 1] -= val;
                }
            }
            sum += diff[i];  // Apply cumulative effect for `i`
        }
        return true;  // If all elements become zero, return true
    }
};