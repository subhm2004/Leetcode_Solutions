class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[nums[i][j]]++;
            }
        }
        int repeated = -1;
        int missing = -1;
        for (int i = 1; i <= n * n; i++) {
            if (freq[i] == 2)
                repeated = i;
            else if (freq[i] == 0)
                missing = i;
        }
        return {repeated, missing};
    }
};