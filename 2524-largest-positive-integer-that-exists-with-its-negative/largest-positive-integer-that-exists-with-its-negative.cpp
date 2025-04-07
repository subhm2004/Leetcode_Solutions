class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set;
        int ans = -1;

        for (auto& num : nums) {
            if (set.count(-num)) {
                int k = abs(num);
                if (k > ans) ans = k;
            }
            set.insert(num);
        }

        return ans;
    }
};