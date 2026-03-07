class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>freq;

        for(auto val:nums){
            freq[val]++;
        }
        for(auto [val,f]:freq){
            if(f == 2) ans.push_back(val);
        }
        return ans;
    }
};