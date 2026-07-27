// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int ans = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
//             }
//         }
//         return ans;
//     }
// };



// class Solution {
//  public:
//   int maxProduct(vector<int>& nums) {
//     int max1 = *max_element(nums.begin(), nums.end());
//     nums.erase(find(nums.begin(), nums.end(), max1));  
//     int max2 = *max_element(nums.begin(), nums.end());
    
//     return (max1 - 1) * (max2 - 1);
//   }
// };

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    priority_queue<int> pq(nums.begin(), nums.end());  // Max heap

    int max1 = pq.top();  
    pq.pop();  
    int max2 = pq.top();  

    return (max1 - 1) * (max2 - 1);
  }
};

