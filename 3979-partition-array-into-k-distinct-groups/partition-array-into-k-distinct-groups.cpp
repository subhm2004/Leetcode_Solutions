class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false; // total elements divide hone chahiye

        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        int total_groups = n / k;

        for (auto [num, count] : freq) {
            if (count > total_groups) return false; 
        }

        return true;
    }
};