class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] < nums[i + 1])
            i--;
        return max(0, i + 1);
    }
};