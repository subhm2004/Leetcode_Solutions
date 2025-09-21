class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {

        int ans = 0;
        for (int& num : nums) {
            if (!(num & 1)) {
                ans |= num;
            }
        }
        return ans;
    }
};