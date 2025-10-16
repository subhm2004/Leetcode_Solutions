class Solution {
public:
    bool is_possible(vector<int>& nums, int k, vector<int>& incresing) {
        int n = nums.size();
        for (int i = 0; i + 2 * k <= n; i++) {
            if (incresing[i + k - 1] >= k && incresing[i + 2 * k - 1] >= k)
                return true;
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> incresing(n, 1);

        // compute incresing streaks
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                incresing[i] = incresing[i - 1] + 1;
        }

        int low = 1, high = n, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (is_possible(nums, mid, incresing)) {
                ans = mid;
                low = mid + 1; // try bigger k
            } else {
                high = mid - 1; // smaller k
            }
        }
        return ans;
    }
};