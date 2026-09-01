class Solution {
public:
    long long power(long long x, long long y) {
        long long mod = 1e9 + 7;
        long long ans = 1;

        while (y > 0) {
            if (y % 2 == 1)
                ans = (ans * x) % mod;

            x = (x * x) % mod;
            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        long long mod = 1e9 + 7;
        long long ans = 0;

        for (long long num : nums) {

            // Last digit = width
            int width = num % 10;

            // Remove width
            num /= 10;

            string s = to_string(num);

            // First width digits = x
            long long x = stoll(s.substr(0, width));

            // Remaining digits = y
            long long y = stoll(s.substr(width));

            // Add x^y
            ans = (ans + power(x, y)) % mod;
        }

        return ans;
    }
};