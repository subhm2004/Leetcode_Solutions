class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, countMax = 0;
        long long ans = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxElement)
                countMax++;

            while (countMax >= k) {
                ans += n - right;

                if (nums[left] == maxElement)
                    countMax--;
                left++;
            }
        }

        return ans;
    }
};
