class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> unique_elements(nums.begin(), nums.end());
        int operations = 0;
        for (int num : unique_elements) {
            if (num > k) {
                operations++;
            } else if (num < k) {
                return -1;
            }
        }
        return operations;
    }
};