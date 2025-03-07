class Solution {
public:
    void findNSum(int l, int r, long long target, int N, vector<int>& nums, vector<int>& result, vector<vector<int>>& results) {
        if (r - l + 1 < N || N < 2 || target < (long long)nums[l] * N || target > (long long)nums[r] * N) {
            return;
        }
        
        if (N == 2) {
            while (l < r) {
                long long sum = (long long)nums[l] + nums[r];
                if (sum == target) {
                    results.push_back(result);
                    results.back().push_back(nums[l]);
                    results.back().push_back(nums[r]);
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++, r--;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        } else {
            for (int i = l; i <= r - N + 1; i++) {
                if (i == l || nums[i] != nums[i - 1]) {
                    result.push_back(nums[i]);
                    findNSum(i + 1, r, target - nums[i], N - 1, nums, result, results);
                    result.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        sort(nums.begin(), nums.end());
        findNSum(0, nums.size() - 1, 0, 3, nums, result, results);
        return results;
    }
};