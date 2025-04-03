// class Solution {
// public:
//     int sumOfBeauties(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;

//         for (int i = 1; i < n - 1; ++i) {
//             bool isBeautiful2 = true;

//             // Check if all elements before nums[i] are smaller
//             for (int j = 0; j < i; ++j) {
//                 if (nums[j] >= nums[i]) {
//                     isBeautiful2 = false;
//                     break;
//                 }
//             }

//             // Check if all elements after nums[i] are greater
//             for (int j = i + 1; j < n; ++j) {
//                 if (nums[j] <= nums[i]) {
//                     isBeautiful2 = false;
//                     break;
//                 }
//             }
//             if (isBeautiful2)
//                 ans += 2;
//             else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
//                 ans += 1;
//         }
//         return ans;
//     }
// };

class Solution {
 public:
  int sumOfBeauties(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    
    // Step 1: Right se minimum values calculate karo
    vector<int> minRight(n);
    minRight[n - 1] = nums[n - 1];
    
    for (int i = n - 2; i >= 2; --i)
      minRight[i] = min(nums[i], minRight[i + 1]);

    int maxLeft = nums[0];

    // Step 2: Har element ko check karo (first aur last ko chhod ke)
    for (int i = 1; i < n - 1; ++i) {
      // Agar current element ka left ka max aur right ka min se beech me hai toh fully beautiful
      if (maxLeft < nums[i] && nums[i] < minRight[i + 1]) {
        ans += 2;  // Fully beautiful
      } 
      // Agar strictly increasing order me hai toh partially beautiful
      else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
        ans += 1;  // Partially beautiful
      }
      // maxLeft update kar do next iteration ke liye
      maxLeft = max(maxLeft, nums[i]);  
    }

    return ans;
  }
};
