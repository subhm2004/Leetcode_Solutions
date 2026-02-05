class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        int left = 0;
        int max_len = 1;

        for (int right = 0; right < n; right++) {

            while (nums[right] > 1LL * nums[left] * k) {
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return n - max_len;
    }
};
