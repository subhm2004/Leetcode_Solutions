class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[mid + 1]) {
                right = mid ;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

// class Solution {
//  public:
//   int findPeakElement(vector<int>& nums) {
//     for (int i = 0; i < nums.size() - 1; i++) {
//       if (nums[i] > nums[i + 1]) {
//         return i;
//       }
//     }
//     return nums.size() - 1;
//   }
// };
