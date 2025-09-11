class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans |= num; // OR of all elements
        }
        return ans;
    }
};
