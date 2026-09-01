class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<bool> seen(101, false);
        vector<bool> bad(101, false);

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (seen[x] && nums[i - 1] != x)
                bad[x] = true;

            seen[x] = true;
        }

        int ans = 0;

        for (int x = 1; x <= 100; x++) {
            if (seen[x] && !bad[x])
                ans++;
        }

        return ans;
    }
};