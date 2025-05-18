class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = 0; j < (int)nums.size(); ++j) {
                if (i != j) {
                    if (nums[i] + nums[j] == target) {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};
