typedef long long ll;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        ll sum = 0;
        int left = 0;
        int max_freq = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while ((ll)(right - left + 1) * nums[right] - sum > k) {
                sum -= nums[left];
                left++;
            }

            max_freq = max(max_freq, right - left + 1);
        }
        return max_freq;
    }
};