class Solution {          // DIFFERENCE ARRAY TECHNIQUE SE HUA HAI + binary search laga hai 
public:
    bool difference_array_technique(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n, 0);

        // Step 1: Apply each query with val = 1 using difference array
        for (int i = 0; i <= k ; i++) {
            int l = queries[i][0], r = queries[i][1];
            int val = queries[i][2] ;

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

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        bool allZero = true;
        for (int val : nums) {
            if (val != 0) {
                allZero = false;
                break;
            }
        }

        if (allZero) {
            return 0;
        }


        int left = 0, right = queries.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (difference_array_technique(nums, queries, mid)) {
                ans = mid + 1;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans; 
    }
};



//-----------------------------------------------------------------------------------------
