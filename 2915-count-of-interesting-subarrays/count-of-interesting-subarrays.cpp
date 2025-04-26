class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();

        // Step 1: Convert karo nums ko 0s aur 1s me
        for (int i = 0; i < n; i++) {
            nums[i] = (nums[i] % m == k) ? 1 : 0;
        }

        unordered_map<int, long long> remainderCount;
        remainderCount[0] = 1; // Base case: sum=0 ke liye ek count already

        long long prefixSum = 0;
        long long ans = 0;

        // Step 2: Array traverse karte hain
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            int currentRem = prefixSum % m;
            int targetRem = (currentRem - k + m) % m;

            // Pehle check karte hain ki target remainder available hai ya nahi
            if (remainderCount.find(targetRem) != remainderCount.end()) {
                ans += remainderCount[targetRem]; // agar hai to add karte hain
            }

            // Apna current remainder count update karte hain
            remainderCount[currentRem]++;
        }

        return ans;
    }
};
