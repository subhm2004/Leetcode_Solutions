class Solution {          // DIFFERENCE ARRAY TECHNIQUE SE HUA HAI 
public:
    bool checkWithDifferenceArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n, 0);

        // Apply queries up to indeval k
        for (int i = 0; i <= k; i++) {
            int l = queries[i][0], r = queries[i][1], val = 1;
            diff[l] += val;
            if (r + 1 < n) diff[r + 1] -= val;
        }

        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            if (nums[i] - cumSum > 0) return false; // nums[i] couldn't be reduced to zero
        }

        return true;
    }

    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if (all_of(nums.begin(), nums.end(), [](int val) { return val == 0; })) {
            return true; // Return true instead of 0
        }

        int left = 0, right = queries.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (checkWithDifferenceArrayTeq(nums, queries, mid)) {
                return true;  // If it works, the array can be reduced to zero
            } else {
                left = mid + 1;
            }
        }
        return false; 
    }
};