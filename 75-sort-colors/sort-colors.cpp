// class Solution {      // Dutch Natioal Flag Algorithm
//  public:
//   void sortColors(vector<int>& nums) {
//     int zero = -1;
//     int one = -1;
//     int two = -1;

//     for (const int num : nums)
//       if (num == 0) {
//         nums[++two] = 2;
//         nums[++one] = 1;
//         nums[++zero] = 0;
//       } else if (num == 1) {
//         nums[++two] = 2;
//         nums[++one] = 1;
//       } else {
//         nums[++two] = 2;
//       }
//   }
// };

// class Solution {     // Counting method 
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
        
//         int count_0 = 0;
//         int count_1 = 0;
//         int count_2 = 0;
        
//         for(int &num : nums) {
//             if(num == 0)
//                 count_0++;
//             else if(num == 1)
//                 count_1++;
//             else
//                 count_2++;
//         }
        
//         for(int i = 0; i<n; i++) {
//             if(count_0 > 0) {
//                 nums[i] = 0;
//                 count_0--;
//             } else if(count_1 > 0) {
//                 nums[i] = 1;
//                 count_1--;
//             } else if(count_2 > 0) {
//                 nums[i] = 2;
//                 count_2--;
//             }
//         }
//     }
// };

class Solution {       // Dutch national flag algorithm ( swap method )
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;   //denotes for 0
        int j = 0;   //denotes for 1
        int k = n-1; //denotes for 2
        
        while ( j <= k) {
            if(nums[j] == 1) {
                j++;
            } else if(nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;
            } else { //nums[j] == 0
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
        }
    }
};