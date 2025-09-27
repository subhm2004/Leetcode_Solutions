class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());

        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int subseq_sum = 0;
        vector<int> subsequence;

        for (int i = 0; i < n; i++) {
            subsequence.push_back(nums[i]);
            subseq_sum += nums[i];
            int remaining_sum = total_sum - subseq_sum;  
            if (subseq_sum > remaining_sum) {
                break;  
            }
        }

        return subsequence;
    }
};