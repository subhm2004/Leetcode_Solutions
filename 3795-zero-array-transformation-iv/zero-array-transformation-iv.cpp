class Solution {
public:
    bool canMakeZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        
        // For each position, collect all query values that can affect it
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            
            vector<int> availableVals;
            
            // Collect all query values from first k queries that cover position i
            for (int j = 0; j < k; j++) {
                int l = queries[j][0], r = queries[j][1], val = queries[j][2];
                if (l <= i && i <= r) {
                    availableVals.push_back(val);
                }
            }
            
            // Check if we can form exactly nums[i] using subset sum DP
            if (!canFormSum(availableVals, nums[i])) {
                return false;
            }
        }
        
        return true;
    }
    
    // Approach 1: Simple recursion (might be slow for large inputs)
    bool canFormSumRecursive(vector<int>& vals, int target, int index) {
        // Base cases
        if (target == 0) return true;  // Found exact sum
        if (index >= vals.size() || target < 0) return false;  // No more elements or negative sum
        
        // Choice 1: Include current element
        // Choice 2: Exclude current element
        return canFormSumRecursive(vals, target - vals[index], index + 1) ||
               canFormSumRecursive(vals, target, index + 1);
    }
    
    // Approach 2: Recursion with _dpization (recommended)
    bool canFormSum_dp(vector<int>& vals, int target, int index, vector<vector<int>>& _dp) {
        // Base cases
        if (target == 0) return true;
        if (index >= vals.size() || target < 0) return false;
        
        // Check if already computed
        if (_dp[index][target] != -1) {
            return _dp[index][target];
        }
        
        // Recursive choices
        bool include = canFormSum_dp(vals, target - vals[index], index + 1, _dp);
        bool exclude = canFormSum_dp(vals, target, index + 1, _dp);
        
        // _dpize and return
        _dp[index][target] = include || exclude;
        return _dp[index][target];
    }
    
    bool canFormSum(vector<int>& vals, int target) {
        if (target == 0) return true;
        if (vals.empty()) return false;
        
        // Option 1: Simple recursion (uncomment to use)
        // return canFormSumRecursive(vals, target, 0);
        
        // Option 2: Recursion with _dpization
        vector<vector<int>> _dp(vals.size(), vector<int>(target + 1, -1));
        return canFormSum_dp(vals, target, 0, _dp);
        
        // Option 3: Keep the DP approach (currently active)
        // vector<bool> dp(target + 1, false);
        // dp[0] = true;
        // for (int val : vals) {
        //     for (int sum = target; sum >= val; sum--) {
        //         if (dp[sum - val]) {
        //             dp[sum] = true;
        //         }
        //     }
        // }
        // return dp[target];
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // Check if already all zeros
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