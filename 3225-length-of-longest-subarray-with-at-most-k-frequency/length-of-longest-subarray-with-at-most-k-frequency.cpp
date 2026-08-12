class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Current element ko window mein add karo
            freq[nums[right]]++;

            // Agar koi element k se zyada baar aa gaya,
            // toh window invalid ho gayi
            while (freq[nums[right]] > k) {

                // Left se elements remove karte jao
                freq[nums[left]]--;
                left++;
            }

            // Ab current window good hai
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};