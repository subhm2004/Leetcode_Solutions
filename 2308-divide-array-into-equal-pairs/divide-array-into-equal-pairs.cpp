class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) 
            ++freq[num];
        
        for (const auto& [key, count] : freq) {
            if (count % 2 != 0) 
                return false;
        }
        return true;
    }
};
