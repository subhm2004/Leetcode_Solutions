class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        vector<int> ans;
        for (int num : nums) {
            ans.push_back(lower_bound(sorted.begin(), sorted.end(), num) - sorted.begin());
        }
        return ans;
    }
};