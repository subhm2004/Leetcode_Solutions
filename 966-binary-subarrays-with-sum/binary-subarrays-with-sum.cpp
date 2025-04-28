typedef unsigned long long ull;
class Solution {
public:
    ull numSubarraysWithSum(vector<int>& nums, ull goal) {
        unordered_map<ull, ull> prefixCount;
        prefixCount[0] = 1; // base case: empty prefix
        
        ull ans = 0, currSum = 0;
        
        for (auto num : nums) {
            currSum += num;
            
            if (prefixCount.find(currSum - goal) != prefixCount.end()) {
                ans += prefixCount[currSum - goal];
            }
            
            prefixCount[currSum]++;
        }
        
        return ans;
    }
};