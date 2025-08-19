class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;

        int n = nums.size();

        int count_sub_array = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] == 0)
                count_sub_array += 1;
            else
                count_sub_array = 0;

            ans += count_sub_array;
        }

        return ans;
    }
};