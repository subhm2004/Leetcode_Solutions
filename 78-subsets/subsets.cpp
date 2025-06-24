class Solution {
public:
    void generate(int idx, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if we've considered all elements
        if (idx == nums.size()) {
            result.push_back(current);  // store the current subset
            return;
        }

        // Exclude the current element
        generate(idx + 1, nums, current, result);

        // Include the current element
        current.push_back(nums[idx]);
        generate(idx + 1, nums, current, result);
        current.pop_back();  // backtrack
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generate(0, nums, current, result);
        return result;
    }
};
