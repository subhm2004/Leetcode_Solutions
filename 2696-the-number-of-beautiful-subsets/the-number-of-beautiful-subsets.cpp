class Solution {
public:
    int count = 0;  

    void backtrack(vector<int>& nums, int k, int i, vector<int>& subset) {
        if(i == nums.size()) {
            if(!subset.empty()) count++;
            return;
        }

        // Option 1: Include nums[i] ko agar ye safe hai 
        bool can_include = true;
        for(int val : subset) {
            if(abs(val - nums[i]) == k) {
                can_include = false;
                break;
            }
        }

        if(can_include) {
            subset.push_back(nums[i]); // include
            backtrack(nums, k, i + 1, subset); // call recursive function again
            subset.pop_back(); // backtrack
        }

        // Option 2: Exclude nums[i]
        backtrack(nums, k, i + 1, subset);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> subset;
        count = 0;
        backtrack(nums, k, 0, subset);
        return count;
    }
};
