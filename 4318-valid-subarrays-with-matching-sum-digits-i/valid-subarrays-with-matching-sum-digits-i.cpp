class Solution {
public:
    long long countValidSubarrays(vector<int>& nums, int x) {

        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        long long maxSum = pref[n];
        long long ans = 0;

        for (int j = 1; j <= n; j++) {

            long long curPref = pref[j];

            long long p = 1;

            while (p <= maxSum) {

                long long L = 1LL * x * p;
                long long R = 1LL * (x + 1) * p - 1;

                if (L > maxSum)
                    break;

                long long left = curPref - R;
                long long right = curPref - L;

                auto it1 = lower_bound(pref.begin(), pref.begin() + j, left);
                auto it2 = upper_bound(pref.begin(), pref.begin() + j, right);

                for (auto it = it1; it != it2; ++it) {

                    long long sum = curPref - *it;

                    if (sum % 10 == x) {
                        ans++;
                    }
                }

                p *= 10;
            }
        }

        return ans;
    }
};