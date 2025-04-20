class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int prev = -1, size = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= prev) {
                prev = nums[i];
                size++;
            }
        }
        
        return size;
    }
};
