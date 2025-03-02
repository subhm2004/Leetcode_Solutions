class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int> count(1001, 0); 
        for (auto& num : nums1) count[num[0]] += num[1];
        for (auto& num : nums2) count[num[0]] += num[1];

        vector<vector<int>> result;
        for (int i = 0; i < 1001; ++i) {
            if (count[i] > 0) result.push_back({i, count[i]});
        }
        return result;
    }
};
