class Solution {
public:
    int GCD(int a, int b) {
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }

    long long LCM(long long a, long long b) {
        return (a * b) / GCD(a, b); 
        // return (a / GCD(a, b)) * b; 
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long  g = nums[i];
            long long l = nums[i];

            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                g = GCD(g, nums[j]);
                l = LCM(l, nums[j]);

                if (prod == g * l)
                    max_len = max(max_len, j - i + 1);
                else if (prod > g * l)
                    break;
            }
        }

        return max_len;
    }
};
