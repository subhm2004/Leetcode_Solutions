// class Solution {
// public:
//     int maximizeExpressionOfThree(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end(), greater<>());
//         int a = nums[0], b = nums[1], c = nums[n-1];
//         return a + b - c;
//     }
// };

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;  
        int min1 = INT_MAX;                 
        
        for (int x : nums) {
            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }
            min1 = min(min1, x);
        }
        
        return max1 + max2 - min1;
    }
};
