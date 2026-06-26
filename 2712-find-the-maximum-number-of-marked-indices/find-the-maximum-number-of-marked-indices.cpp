// Same as LC 2856 
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = (n + 1) / 2;

        int ans = 0;

        while (i < n / 2 && j < n) {
            if (2LL * nums[i] <= nums[j]) {
                ans += 2;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return ans;
    }
};