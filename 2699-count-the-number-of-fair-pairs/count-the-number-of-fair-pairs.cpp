typedef long long ll;
class Solution {
public:
    int lowerBound(const vector<int>& nums, int start, int end, int target) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }

    int upperBound(const vector<int>& nums, int start, int end, int target) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        ll ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int j = lowerBound(nums, i + 1, nums.size(), lower - nums[i]);
            int k = upperBound(nums, i + 1, nums.size(), upper - nums[i]);
            ans += k - j;
        }
        return ans;
    }
};
