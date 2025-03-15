class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> count;
        int sum = 0;

        for (int num : nums) 
            count[num]++; // Count occurrences

        for (auto& [num, freq] : count) 
            if (freq == 1) 
                sum += num; // Add unique numbers to sum

        return sum;
    }
};
