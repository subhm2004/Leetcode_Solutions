// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = 0;
        
//         for (int i = 0; i < n; i++) {
//             int oddCount = 0;
//             for (int j = i; j < n; j++) {
//                 if (nums[j] % 2 != 0) {
//                     oddCount++;
//                 }
                
//                 if (oddCount == k) {
//                     ans++;
//                 }
//                 // optimization: if oddCount > k, no need to continue
//                 else if (oddCount > k) {
//                     break;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };


#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Saare numbers ko 0 ya 1 me convert karo (even -> 0, odd -> 1)
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                nums[i] = 0; // Agar even hai to 0 kar do
            } else {
                nums[i] = 1; // Agar odd hai to 1 kar do
            }
        }
        
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // Important: shuruat me 0 sum ke liye ek entry daal do
        
        int prefixSum = 0, ans = 0;
        
        // Step 2: Traverse karo array ko aur prefix sum calculate karte jao
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i]; // ab tak ka prefix sum add karo
            
            // Check karo ki prefixSum - k pehle kitni baar aaya tha
            if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
                ans += prefixCount[prefixSum - k]; // agar mila to utne subarrays add karo
            }
            
            // Apna current prefix sum bhi map me store/update kar do
            prefixCount[prefixSum]++;
        }
        
        return ans;  
    }
};
