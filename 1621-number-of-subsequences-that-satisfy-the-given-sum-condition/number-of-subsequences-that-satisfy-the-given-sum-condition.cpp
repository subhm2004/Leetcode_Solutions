class Solution {
public:
    int MOD = 1e9 + 7;   

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Step 1: Sort the numsay
        sort(nums.begin(), nums.end());

        // Step 2: PrecoMODpute powers of 2 up to n
        vector<int> power(n, 1);  // power[i] = 2^i
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        // Step 3: Two pointers approach
        int left = 0, right = n - 1;
        int ans = 0;

        while (left <= right) {
            // If the sMODallest + largest is within target
            if (nums[left] + nums[right] <= target) {
                int diff = right - left;   
                ans = (ans + power[diff]) % MOD;  // Add all valid subsequences
                left++;
            } else {
                // If sum is too big, reduce the biggest nuMODber
                right--;
            }
        }

        return ans;
    }
};
