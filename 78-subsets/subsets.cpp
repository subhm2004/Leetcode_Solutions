// class Solution {       // Solution using inclusion ans exclusion approach
// public:
//     void generate(int idx, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
//         // Base case: if we've considered all elements
//         if (idx == nums.size()) {
//             ans.push_back(current);  // store the current subset
//             return;
//         }

//         // Exclude the current element
//         generate(idx + 1, nums, current, ans);

//         // Include the current element
//         current.push_back(nums[idx]);
//         generate(idx + 1, nums, current, ans);
//         current.pop_back();  // backtrack
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> current;
//         generate(0, nums, current, ans);
//         return ans;
//     }
// };
//-------------------------------------------------------------------------
class Solution {     // Solution using backtracking 
public:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
        ans.push_back(current);  // add current subset

        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);         // choose
            backtrack(i + 1, nums, current, ans); // explore
            current.pop_back();                 // un-choose (backtrack)
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(0, nums, current, ans);
        return ans;
    }
};

