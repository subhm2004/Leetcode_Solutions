class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        for (int num : nums) {
            if (num < k)
                count++;
            else
                continue;
        }
        return count;
    }
};