class Solution {
public:
    bool can_make_zero(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            
            vector<int> available_arr;
            for (int j = 0; j < k; j++) {
                int l = queries[j][0], r = queries[j][1], val = queries[j][2];
                if (l <= i && i <= r) {
                    available_arr.push_back(val);
                }
            }

            if (!can_form_sum(available_arr, nums[i])) {
                return false;
            }
        }
        return true;
    }
    
    bool subset_sum_ME(vector<int>& arr, int target, int i, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i >= arr.size() || target < 0) return false;
        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        bool include = subset_sum_ME(arr, target - arr[i], i + 1, dp);
        bool exclude = subset_sum_ME(arr, target, i + 1, dp);
        return dp[i][target] = include || exclude;
    }
    
    bool can_form_sum(vector<int>& arr, int target) {
        if (target == 0) return true;
        if (arr.empty()) return false;
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
        return subset_sum_ME(arr, target, 0, dp);
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

        int left = 1, right = queries.size();
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (can_make_zero(nums, queries, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
