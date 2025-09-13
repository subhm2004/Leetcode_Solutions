// class Solution {
// public:
//     int xorBeauty(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 for (int k = 0; k < n; k++) {
//                     int effective_value = (nums[i] | nums[j]) & nums[k]; // effective value
//                     ans ^= effective_value; // XOR karte chalo 
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};
