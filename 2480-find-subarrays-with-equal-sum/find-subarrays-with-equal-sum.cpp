class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        // unordered_set<int> seen;
        // for (int i = 0; i < nums.size() - 1; ++i) {
        //     int sum = nums[i] + nums[i + 1];
        //     if (seen.count(sum))
        //         return true;
        //     seen.insert(sum);
        // }
        // return false;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int sum1 = nums[i] + nums[i + 1];
            for (int j = 0; j < i; ++j) {
                int sum2 = nums[j] + nums[j + 1];
                if (sum1 == sum2)
                    return true;
            }
        }
        return false;
    }
};