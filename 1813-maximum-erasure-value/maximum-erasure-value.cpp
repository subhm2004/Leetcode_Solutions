class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int start = 0, curr_sum = 0, maxi = 0;

        for (int end = 0; end < nums.size(); ++end) {
            while (seen.count(nums[end])) {
                seen.erase(nums[start]);
                curr_sum -= nums[start];
                start++;
            }

            seen.insert(nums[end]);
            curr_sum += nums[end];
            maxi = max(maxi, curr_sum);
        }

        return maxi;
    }
};
