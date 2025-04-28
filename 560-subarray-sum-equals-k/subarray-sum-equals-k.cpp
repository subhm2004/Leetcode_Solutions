// class Solution {
//  public:
//   int subarraySum(vector<int>& nums, int k) {
//     int ans = 0;

//     for (int i = 0; i < nums.size(); ++i) {
//       int sum = 0;

//       for (int j = i; j < nums.size(); ++j) {
//         sum += nums[j];
//         if (sum == k) {
//           ans++;
//         }
//       }
//     }

//     return ans;
//   }
// };

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0; // Yeh count karega valid subarrays ko
        int prefixSum = 0; // Yeh current prefix sum ko track karega
        
        // Hash map banate hain jo prefix sums ki frequency rakhega
        unordered_map<int, int> prefixSumCount;
        
        // Initialize karte hain map ko jisme prefix sum 0 ka frequency 1 hoga
        // Yeh case handle karta hai jab subarray ka sum directly k ho
        prefixSumCount[0] = 1;

        for (int num : nums) {
            // Running sum (prefix sum) ko update karte hain
            prefixSum += num;
            
            // Agar prefixSum - k map mein pehle se hai toh iska matlab
            // koi subarray exist karta hai jiska sum k ke barabar hai
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                ans += prefixSumCount[prefixSum - k];
            }

            // Current prefix sum ki frequency ko update karte hain
            prefixSumCount[prefixSum]++;
        }

        return ans; // Total valid subarrays ko return karte hain
    }
};


