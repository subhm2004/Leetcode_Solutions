class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());

     
        vector<int> freq(n + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // 1 to n-1 should appear once
        for (int i = 1; i < n; i++) {

            if (freq[i] != 1) {
                return false;
            }
        }

        // n should appear twice
        return freq[n] == 2;
    }
};