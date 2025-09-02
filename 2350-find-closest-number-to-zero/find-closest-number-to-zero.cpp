class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        for (int x : nums) {
            if (abs(x) < abs(closest) || 
               (abs(x) == abs(closest) && x > closest)) {
                closest = x;
            }
        }
        return closest;
    }
};
