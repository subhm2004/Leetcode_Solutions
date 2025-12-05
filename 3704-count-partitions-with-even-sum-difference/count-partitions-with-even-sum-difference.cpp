class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int x : nums) total += x;

        if (total % 2 != 0) return 0;

        return n - 1;
    }
};
