class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());
        int maxElement = INT_MIN, maxSum = 0;

        for (auto& num : unique) {
            maxElement = max(maxElement, num);
            maxSum = max(maxSum, num + maxSum);
        }

        return maxElement < 1 ? maxElement : maxSum;
    }
};