// Similar to LC 974
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();

        // Step 1: Convert nums into 0s and 1s
        for (int i = 0; i < n; i++) {
            nums[i] = (nums[i] % m == k) ? 1 : 0;
        }

        unordered_map<int, long long> remainderCount;
        remainderCount[0] = 1; // Base case: sum=0 initially

        long long prefixSum = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            int currentRem = prefixSum % m;
            int targetRem = (currentRem - k + m) % m;

            ans += remainderCount[targetRem];
            remainderCount[currentRem]++;
        }

        return ans;
    }
};
