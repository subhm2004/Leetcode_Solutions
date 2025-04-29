// class Solution {           // Brute Force TLE 40/46
// public:
//     int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
//         int count = 0;  

//         for (int i = 0; i < nums.size(); i++) {
//             int maxElement = nums[i];  // Subarray ka maximum element track karna, initially nums[i] se start karte hain

//             // Loop over all possible ending points of subarrays from the current starting point
//             for (int j = i; j < nums.size(); j++) {
//                 maxElement = max(maxElement, nums[j]);
                
//                 // Agar max element left aur right ke range mein hai
//                 if (maxElement >= left && maxElement <= right) {
//                     count++;  
//                 }
//             }
//         }

//         return count;  
//     }
// };

class Solution {
public:
    // Ye function count karta hai subarrays jinka max element ≤ bound ho
    int countSubarraysWithMaxAtMost(vector<int>& nums, int bound) {
        int count = 0, length = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= bound) {
                length++;       // Current element valid hai, to window ki length badhao
            } else {
                length = 0;     // Invalid element mila, to window reset karo
            }
            count += length;    // Har step pe valid subarrays add karte jao
        }

        return count;
    }

    // Final answer nikalte hain valid = atMost(right) - atMost(left-1)
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countSubarraysWithMaxAtMost(nums, right) -
               countSubarraysWithMaxAtMost(nums, left - 1);
    }
};
