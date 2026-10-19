class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int count = 0;
        int lessThan = 0;

        for (int num : nums) {
            if (num < target) {
                lessThan++;
            } else if (num == target) {
                count++;
            }
        }

        for (int i = 0; i < count; ++i) {
            ans.push_back(lessThan + i);
        }

        return ans;
    }
};
