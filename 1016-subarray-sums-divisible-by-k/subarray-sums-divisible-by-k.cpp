// kuch naya seekhne ko milega is question se

// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;

//         // Create prefix sum array
//         vector<int> prefixSum(n + 1, 0);
//         for (int i = 0; i < n; ++i) {
//             prefixSum[i + 1] = prefixSum[i] + nums[i];
//         }

//         // Check all subarrays using prefix sum
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j <= n; ++j) {
//                 int sum = prefixSum[j] - prefixSum[i];
//                 if (sum % k == 0) {
//                     ++count;
//                 }
//             }
//         }

//         return count;
//     }
// };




class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Remainders ki frequency store karne ke liye hash map
        unordered_map<int, int> remainderCount;
        int prefixSum = 0;
        
        // Remainder 0 ko initially 1 set karte hain, taaki wo subarrays jo index 0 se start karte hain unhe count kar sake
        remainderCount[0] = 1;
        
        int ans = 0;
        
        // Array ko loop karte hain
        for (int i = 0; i < n; ++i) {
            // Prefix sum update karte hain
            prefixSum += nums[i];
            
            // Prefix sum ko k se divide karke remainder nikaalte hain
            int remainder = prefixSum % k;
            
            // Agar remainder negative hai, toh usse positive banate hain
            if (remainder < 0) {
                remainder += k;
            }
            
            // Agar remainder pehle se map mein hai, toh iska matlab hai ki kuch subarrays
            // pehle ke indices se current index tak sum ko k se divisible bana rahe hain
            if (remainderCount.find(remainder) != remainderCount.end()) {
                ans += remainderCount[remainder];
            }
            
            // Current remainder ki count ko increment karte hain
            remainderCount[remainder]++;
        }
        
        return ans;  // Final answer return karte hain
    }
};
