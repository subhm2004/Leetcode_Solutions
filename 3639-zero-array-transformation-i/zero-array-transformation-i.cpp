class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n, 0);

        // Step 1: Apply each query with val = 1 using difference array
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            int val = 1;

            diff[l] += val;
            if (r + 1 < n)
                diff[r + 1] -= val;
        }

        // Step 2: Convert diff to cumulative sum in-place
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        // Step 3: Check if nums[i] - diff[i] <= 0 for all i
        for (int i = 0; i < n; i++) {
            if (nums[i] - diff[i] > 0) {
                return false;  // Not enough reductions
            }
        }

        return true;  // All values reduced to 0 or less
    }
};
