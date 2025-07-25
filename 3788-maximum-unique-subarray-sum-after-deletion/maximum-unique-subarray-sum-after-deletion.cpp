class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            if (num > 0) {
                count[num]++;
            }
        }
        
        vector<int> unique_positive_nums;
        for (auto& p : count) {
            unique_positive_nums.push_back(p.first);
        }
        
        if (unique_positive_nums.empty()) {
            return *max_element(nums.begin(), nums.end());
        }
        
        long long ans = 0;
        for (int num : unique_positive_nums) {
            ans += num;
        }
        
        return ans;
    }
};
