class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Step 1: Frequency count
         unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Max frequency = rows needed
        // The maximum frequency determines the minimum number of rows needed
        int maxFreq = 0;
        for (auto& [num, count] : freq) {
            maxFreq = max(maxFreq, count);
        }

        // Step 3: Prepare 2D array with maxFreq rows
        vector<vector<int>> ans(maxFreq);

        // Step 4: Har number ko uski frequency bar alag-alag rows me daal do
        for (auto& [num, count] : freq) {
            for (int i = 0; i < count; ++i) {
                ans[i].push_back(num);
            }
        }

        return ans;
    }
};
