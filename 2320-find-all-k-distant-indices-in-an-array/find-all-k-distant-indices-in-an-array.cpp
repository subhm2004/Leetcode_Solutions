class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int> valid;  // Step 1: unique indices

        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == key) {        // |i - j| <= k ka mtlb hia  j - k <= i <= j + k

                int start = max(0, j - k);     
                int end = min((int)nums.size() - 1, j + k);
                for (int i = start; i <= end; ++i) {
                    valid.insert(i);  // Step 2: mark all k-distant indices
                }
            }
        }

        vector<int> ans(valid.begin(), valid.end());
        sort(ans.begin(), ans.end());  // Step 3: sort
        return ans;
    }
};
