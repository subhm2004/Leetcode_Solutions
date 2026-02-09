// sum(l..r) = pref[r+1] - pref[l]
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        int ans = 0;

        for(int i = 0; i < n - 1; i++) {

            int right_sum = pref[n] - pref[i + 1];
            int right_count = n - i - 1;

            if(nums[i] * right_count > right_sum) {
                ans++;
            }
        }
        return ans;
    }
};