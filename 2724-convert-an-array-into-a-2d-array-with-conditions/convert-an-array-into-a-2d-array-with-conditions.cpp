class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // The maximum frequency determines the minimum number of rows needed
        int maxFreq = 0;
        for (auto& [num, count] : freq) {
            maxFreq = max(maxFreq, count);
        }

        // Prepare the ans with the required number of rows
        vector<vector<int>> ans(maxFreq);

        // Distribute each number across different rows
        for (auto& [num, count] : freq) {
            for (int i = 0; i < count; ++i) {
                ans[i].push_back(num);
            }
        }

        return ans;
    }
};
