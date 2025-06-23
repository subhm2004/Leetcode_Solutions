class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            int val = -1;

            for (int i = 0; i < num; ++i) {
                if ((i | (i + 1)) == num) {
                    val = i;
                    break;
                }
            }

            ans.push_back(val);
        }

        return ans;
    }
};
