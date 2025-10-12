class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num]++;
        }
        int total_sum = 0;
        for (auto& [num, count] : freq) {
            if (count % k == 0) {
                total_sum += num * count;
            }
        }

        return total_sum;
    }
};