// class Solution {
// public:
//     void backtrack(int start, vector<int>& nums, vector<int>& current,
//                    vector<vector<int>>& ans) {
//         ans.push_back(current); // Add the current subset to the ans

//         for (int i = start; i < nums.size(); ++i) {
//             // Skip duplicates
//             if (i > start && nums[i] == nums[i - 1])
//                 continue;

//             // Include nums[i] in the subset
//             current.push_back(nums[i]);

//             // Recurse with the next elements
//             backtrack(i + 1, nums, current, ans);

//             // Backtrack: remove last element
//             current.pop_back();
//         }
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         vector<int> current;
//         backtrack(0, nums, current, ans);
//         return ans;
//     }
// };

//---------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort to handle duplicates
        int n = nums.size();
        int total = 1 << n;  // total subsets = 2^n
        set<vector<int>> unique_Subsets;  // to avoid duplicates

        for (int mask = 0; mask < total; mask++) {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            unique_Subsets.insert(subset);  // set handles duplicates
        }

        // convert set to vector
        vector<vector<int>> ans(unique_Subsets.begin(), unique_Subsets.end());
        return ans;
    }
};
