// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() / 2];
//     }
// };
class Solution {
public:  // moor's voting algorithm 
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                 major = nums[i];

                count = 1;
                continue;
            }
            if (nums[i] == major)
                count++;
            else
                count--;
        }
        return major;
    }
};