// class Solution {
// public:
//     int uniqueXorTriplets(vector<int>& nums) {
//         int n = nums.size();
//         unordered_set<int> unique_XORs;

//         // Generate all possible triplets (i <= j <= k)
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 for (int k = j; k < n; k++) {
//                     int xor_val = nums[i] ^ nums[j] ^ nums[k];
//                     unique_XORs.insert(xor_val);
//                 }
//             }
//         }

//         return unique_XORs.size();
//     }
// };



class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> set_1;  
        int n = nums.size();
        if (n < 3) return n;  

        // Sabhi pairs ke XOR ko 'set_1' mein store karte hain
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {  // j ko i ke baad se start karenge, taaki duplicates na ho
                set_1.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int>set_2;
        // 'set_1' ke XOR values ko nums ke har element ke saath XOR karenge aur triplet XOR find karenge
        for (int num : set_1) {
            for (int x : nums) {
                set_2.insert(num ^ x);
            }
        }

        // 'set_2' ka size unique triplet XORs ka count dega
        return set_2.size();  
    }
};
