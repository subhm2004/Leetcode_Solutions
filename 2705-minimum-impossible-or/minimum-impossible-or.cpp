class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        // Create a map to store which numbers are present
        unordered_map<int, int> mp;
        
        // Mark all numbers as present in the map
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
        }
        
        // Start with the smallest power of 2
        int ans = 1;
        
        // Keep checking if current power of 2 exists in the array
        // If it exists, move to the next power of 2
        // If it doesn't exist, that's our answer
        while(mp.find(ans) != mp.end()) {
            ans *= 2;  // Move to next power of 2: 1, 2, 4, 8, 16, ...
        }
        
        return ans;
    }
};