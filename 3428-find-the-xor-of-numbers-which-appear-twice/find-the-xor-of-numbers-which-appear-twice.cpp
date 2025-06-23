class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int xor_result = 0;
        for (auto& [num, count] : freq) {
            if (count == 2) {
                xor_result ^= num;
            }
        }

        return xor_result;
    }
};