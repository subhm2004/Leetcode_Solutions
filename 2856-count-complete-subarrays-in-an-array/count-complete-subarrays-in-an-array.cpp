class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uniqueSet(nums.begin(), nums.end());
        int total_unique_elements = uniqueSet.size();

        unordered_map<int, int> freq;
        int ans = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;

            while (freq.size() == total_unique_elements) {
                ans += (n - right);
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
   
            }
        }

        return ans;
    }
};
