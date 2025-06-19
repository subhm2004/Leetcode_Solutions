class Solution {
public:
    // Returns the actual partitions (each group)
    vector<vector<int>> get_Partitions(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        vector<int> current_Group;
        int mini = nums[0];
        current_Group.push_back(mini);

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - mini > k) {
                ans.push_back(current_Group); // save current group
                current_Group.clear();
                mini = nums[i];
            }
            current_Group.push_back(nums[i]);
        }

        // push the last group
        if (!current_Group.empty())
            ans.push_back(current_Group);

        return ans;
    }

    // Returns just the count of groups
    int partitionArray(vector<int>& nums, int k) {
        vector<vector<int>> partitions = get_Partitions(nums, k);
        return partitions.size();
    }
};
