// class Solution {
// public:
//     int maxProductDifference(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
//     }
// };
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int lowest = INT_MAX;
        int secondLowest = INT_MAX;
        int secondHighest = INT_MIN;
        int highest = INT_MIN;
        for (int num: nums) {
            if (num < lowest) {
                secondLowest = lowest;
                lowest = num;
            }
            else if (num < secondLowest) {
                secondLowest = num;
            }
            
            if (num > highest) {
                secondHighest = highest;
                highest = num;
            }
            else if (num > secondHighest) {
                secondHighest = num;
            }
        }

        return (highest * secondHighest) - (secondLowest * lowest);
    }
};