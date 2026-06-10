
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;

        for (const int num : nums) {
            count[num]++;
        }

        for (const auto& pair : count) {
            if (pair.second == 1) {
                return pair.first;
            }
        }

        return -1;
    }
};