// typedef unsigned long long ull;
// class Solution {
// public:
//     ull numSubarraysWithSum(vector<int>& nums, ull goal) {
//         unordered_map<ull, ull> prefixCount;
//         prefixCount[0] = 1; // base case: empty prefix
        
//         ull ans = 0, currSum = 0;
        
//         for (auto num : nums) {
//             currSum += num;
            
//             if (prefixCount.find(currSum - goal) != prefixCount.end()) {
//                 ans += prefixCount[currSum - goal];
//             }
            
//             prefixCount[currSum]++;
//         }
        
//         return ans;
//     }
// };

class Solution {
public:
    // ye function find krega number od subarray with sum<= goal
    int find_Total_sub_array(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int left = 0, ans = 0, sum = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            
            ans += (right - left + 1);
        }
        
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Atmost K ka sum nikla diya hai isse
        return find_Total_sub_array(nums, goal) - find_Total_sub_array(nums, goal - 1);
    }
};
