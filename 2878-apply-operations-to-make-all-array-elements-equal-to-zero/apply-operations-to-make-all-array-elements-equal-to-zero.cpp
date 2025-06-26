class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int curr = 0;

        for (int i = 0; i < n; ++i) {
            curr += diff[i];

            int val = nums[i] - curr;

            if (val < 0) return false;
            if (val == 0) continue;

            if (i + k > n) return false;

            curr += val;
            diff[i + k] -= val;
        }

        return true;
    }
};
