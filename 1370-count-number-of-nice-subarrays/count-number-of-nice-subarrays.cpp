class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int>& nums, int k) {
        int left = 0;
        int count = 0;
        int odd_count = 0;

        // Iterate through the array with a for loop using 'right' pointer
        for (int right = 0; right < nums.size(); ++right) {
            // If the current number is odd, increase the odd count
            if (nums[right] % 2 != 0) {
                odd_count++;
            }

            // Shrink the window from the left when there are more than 'k' odd numbers
            while (odd_count > k) {
                if (nums[left] % 2 != 0) {
                    odd_count--;
                }
                left++;
            }

            // Add the number of valid subarrays ending at 'right'
            count += (right - left + 1);
        }

        return count;
    }
};
//-----------------------------------------------------

// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         // Step 1: Saare numbers ko 0 ya 1 me convert karo (even -> 0, odd -> 1)
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % 2 == 0) {
//                 nums[i] = 0; // Agar even hai to 0 kar do
//             } else {
//                 nums[i] = 1; // Agar odd hai to 1 kar do
//             }
//         }
        
//         unordered_map<int, int> prefixCount;
//         prefixCount[0] = 1; // Important: shuruat me 0 sum ke liye ek entry daal do
        
//         int prefixSum = 0, ans = 0;
        
//         // Step 2: Traverse karo array ko aur prefix sum calculate karte jao
//         for (int i = 0; i < n; i++) {
//             prefixSum += nums[i]; // ab tak ka prefix sum add karo
            
//             // Check karo ki prefixSum - k pehle kitni baar aaya tha
//             if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
//                 ans += prefixCount[prefixSum - k]; // agar mila to utne subarrays add karo
//             }
            
//             // Apna current prefix sum bhi map me store/update kar do
//             prefixCount[prefixSum]++;
//         }
        
//         return ans;  
//     }
// };
