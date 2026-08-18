class Solution {
public:
    void countSubarrays(const vector<int>& nums, int k, int start, unordered_map<int, int>& freq) {
        if (start > nums.size() - k) return;

        unordered_map<int, bool> seen;
        for (int i = start; i < start + k; ++i) {
            if (!seen[nums[i]]) {
                freq[nums[i]]++;
                seen[nums[i]] = true;
            }
        }

        countSubarrays(nums, k, start + 1, freq);
    }

    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        countSubarrays(nums, k, 0, freq);

        int result = -1;
        for (auto& [num, count] : freq) {
            if (count == 1) {
                result = max(result, num);
            }
        }

        return result;
    }
};

