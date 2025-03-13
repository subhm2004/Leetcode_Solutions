class Solution {
public:
    bool isZeroArray(vector<int>& nums) {
        return all_of(nums.begin(), nums.end(), [](int x) { return x == 0; });
    }

    bool canMakeZeroRecursive(vector<int>& nums, 
                            vector<vector<int>>& queries, 
                              int k, vector<int>& diff, int i) {
        if (i == k) {
            int total = 0;
            for (int j = 0; j < nums.size(); ++j) {
                total += diff[j];
                if (total < nums[j]) return false;
            }
            return true;
        }

        int l = queries[i][0], r = queries[i][1], val = queries[i][2];
        diff[l] += val;
        if (r + 1 < nums.size()) diff[r + 1] -= val;

        return canMakeZeroRecursive(nums, queries, k, diff, i + 1);
    }

    bool canMakeZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(nums.size() + 1, 0);
        return canMakeZeroRecursive(nums, queries, k, diff, 0);
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if (isZeroArray(nums)) return 0;

        int left = 1, right = queries.size(), ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canMakeZero(nums, queries, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
