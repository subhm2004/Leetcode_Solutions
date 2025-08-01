// class Solution {   // Brute force solution 
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int n = nums.size(), ans = 0;

//         for (int i = 0; i < n - 2; ++i) {
//             int diff = nums[i + 1] - nums[i];

//             for (int j = i + 2; j < n; ++j) {
//                 if (nums[j] - nums[j - 1] == diff)
//                     ans++;
//                 else
//                     break;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int count = 0, total = 0;

        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                count++;          
                total += count;    
            } else {
                count = 0;       
            }
        }

        return total;
    }
};
