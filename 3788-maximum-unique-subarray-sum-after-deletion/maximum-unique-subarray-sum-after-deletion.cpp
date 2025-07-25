class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> unique_nums(nums.begin(), nums.end());
        int max_element = INT_MIN, max_sum = 0;

        for (auto& num : unique_nums) {
            max_element = max(max_element, num);
            max_sum = max(max_sum, num + max_sum);
        }

        return max_element < 1 ? max_element : max_sum;
    }
};