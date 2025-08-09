class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
         unordered_map<int, int> mp;
        
         for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
        }
        
         int ans = 1;
        
          while(mp.find(ans) != mp.end()) {
            ans *= 2;   
        }
        
        return ans;
    }
};