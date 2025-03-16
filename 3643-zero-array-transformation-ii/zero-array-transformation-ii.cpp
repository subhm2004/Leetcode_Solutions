class Solution {
public:
    bool checkWithDifferenceArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n, 0);

        // Apply queries up to index k
        for (int i = 0; i <= k; i++) {
            int l = queries[i][0], r = queries[i][1], x = queries[i][2];
            diff[l] += x;
            if (r + 1 < n) diff[r + 1] -= x;
        }

        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            if (nums[i] - cumSum > 0) return false; // nums[i] couldn't be reduced to zero
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return 0; // If nums is already all zeroes
        }
        int left = 0, right = queries.size() - 1, ans = -1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (checkWithDifferenceArrayTeq(nums, queries, mid)) {
                ans = mid + 1; // Convert 0-based index to count of queries
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};