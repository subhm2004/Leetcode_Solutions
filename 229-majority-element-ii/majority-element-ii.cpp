class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<int> ans;
        for (auto& pair : freq) {
            if (pair.second > n / 3) {
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};