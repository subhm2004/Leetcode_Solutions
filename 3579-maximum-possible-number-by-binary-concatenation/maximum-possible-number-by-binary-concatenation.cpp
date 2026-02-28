class Solution {
public:
    int binary_concatination(int a, int b, int c) {
        int length_of_B = 32 - __builtin_clz(b);
        int length_of_C = 32 - __builtin_clz(c);

        long long ans = a;
        ans = (ans << length_of_B) | b;
        ans = (ans << length_of_C) | c;

        return (int)ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        int ans = 0;

        ans = max(ans, binary_concatination(a,b,c));
        ans = max(ans, binary_concatination(a,c,b));
        ans = max(ans, binary_concatination(b,a,c));
        ans = max(ans, binary_concatination(b,c,a));
        ans = max(ans, binary_concatination(c,a,b));
        ans = max(ans, binary_concatination(c,b,a));

        return ans;
    }
};