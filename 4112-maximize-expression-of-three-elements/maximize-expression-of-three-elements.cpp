class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<>());
        int a = nums[0], b = nums[1], c = nums[n-1];
        return a + b - c;
    }
};