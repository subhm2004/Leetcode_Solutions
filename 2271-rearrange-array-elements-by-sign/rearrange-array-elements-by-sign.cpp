class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int positive_Index = 0;
        int negative_Index = 1;

        for (int &num : nums) {
            if (num >= 0) {
                ans[positive_Index] = num;
                positive_Index += 2;
            } else {
                ans[negative_Index] = num;
                negative_Index += 2;
            }
        }

        return ans;
    }
};
