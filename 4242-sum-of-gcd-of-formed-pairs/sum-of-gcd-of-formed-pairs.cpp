class Solution {
public:
    int GCD(int a, int b) {
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }

    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        vector<long long> prefix_gcd(n);

        int maxi = 0;

        for (int i = 0; i < n; i++) {

            // maxi = max_element(nums.begin(), nums.begin() + i + 1)
            maxi = max(maxi, nums[i]);   

            prefix_gcd[i] = GCD(nums[i], maxi);
        }

        sort(prefix_gcd.begin(), prefix_gcd.end());

        long long ans = 0;

        int l = 0, r = n - 1;

        while (l < r) {
            ans += GCD(prefix_gcd[l], prefix_gcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};