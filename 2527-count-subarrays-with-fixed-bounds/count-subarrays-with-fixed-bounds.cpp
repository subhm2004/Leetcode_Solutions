// class Solution {
//     public:
//         long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//             long count = 0;
//             for (int i = 0; i < nums.size(); i++) {
//                 int mini = INT_MAX, maxi = INT_MIN;
//                 for (int j = i; j < nums.size(); j++) {
//                     mini = min(mini, nums[j]);
//                     maxi = max(maxi, nums[j]);
//                     if (mini == minK && maxi == maxK) ++count;
//                 }
//             }
//             return count;
//         }
//     };

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int lastMinK = -1, lastMaxK = -1, lastInvalid = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            // Agar current element [minK, maxK] ke bahar hai toh usko invalid mark karo
            if (nums[i] < minK || nums[i] > maxK) {
                lastInvalid = i;  
            }
            
            // Agar current element minK ke barabar hai toh uska index update karo
            if (nums[i] == minK) {
                lastMinK = i;  
            }
            
            // Agar current element maxK ke barabar hai toh uska index update karo
            if (nums[i] == maxK) {
                lastMaxK = i;  
            }
            
            // Jab tak minK aur maxK dono mile hue hain tab tak hi valid subarrays count kar sakte hain
            if (lastMinK != -1 && lastMaxK != -1) {
                // Valid subarrays ka count add karo jo lastInvalid ke baad start hote hain
                count += max(0, min(lastMinK, lastMaxK) - lastInvalid);
            }
        }

        return count;
    }
};
