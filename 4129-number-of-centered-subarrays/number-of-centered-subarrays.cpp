class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;  

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            unordered_set<long long> seen;

            for (int j = i; j < n; j++) {
                sum += nums[j];
                seen.insert(nums[j]);
                if (seen.count(sum)) ans++;
            }
        }
        return ans;
    }
};
