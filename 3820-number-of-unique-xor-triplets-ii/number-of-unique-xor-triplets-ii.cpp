class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        unordered_set<int> pairXor;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> ans;

        for (int x : pairXor) {
            for (int y : nums) {
                ans.insert(x ^ y);
            }
        }

        return ans.size();
    }
};