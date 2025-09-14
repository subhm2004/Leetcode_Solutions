class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        // step 1: remove duplicates
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> unique_nums(s.begin(), s.end());

        // step 2: sort in descending order
        sort(unique_nums.begin(), unique_nums.end(), greater<int>());

        // step 3: collect at most k elements without resize
        vector<int> ans;
        for (int i = 0; i < k && i < unique_nums.size(); i++) {
            ans.push_back(unique_nums[i]);
        }

        return ans;
    }
};