using ll = long long;
class Solution {
public:
    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> result(n, 0);

        unordered_map<int, ll> count, prefix_sum;

        /*
         * LEFT → RIGHT PASS (left side ka contribution)
         *
         * Jab hum index i pe hain, left mein k same elements
         * aa chuke hain at indices j1, j2, ... jk
         *
         * Kyunki i > j (left wale indices chhote hain):
         *   |i - j1| + |i - j2| + ... + |i - jk|
         *   = (i - j1) + (i - j2) + ... + (i - jk)
         *   = (i + i + ... k times) - (j1 + j2 + ... + jk)
         *   = i*k - prefix_sum
         */
        for (int i = 0; i < n; i++) {
            int v = nums[i];

            ll k = count[v];
            ll s = prefix_sum[v];

            result[i] += (ll)i * k - s; // i*k - (j1+j2+...+jk)

            count[v]++;
            prefix_sum[v] += i;
        }

        count.clear();
        prefix_sum.clear();

        /*
         * RIGHT → LEFT PASS (right side ka contribution)
         *
         * Jab hum index i pe hain, right mein k same elements
         * aa chuke hain at indices j1, j2, ... jk
         *
         * Kyunki j > i (right wale indices bade hain):
         *   |i - j1| + |i - j2| + ... + |i - jk|
         *   = (j1 - i) + (j2 - i) + ... + (jk - i)
         *   = (j1 + j2 + ... + jk) - (i + i + ... k times)
         *   = prefix_sum - i*k
         */
        for (int i = n - 1; i >= 0; i--) {
            int v = nums[i];

            ll k = count[v];
            ll s = prefix_sum[v];

            result[i] += s - (ll)i * k; // (j1+j2+...+jk) - i*k

            count[v]++;
            prefix_sum[v] += i;
        }

        return result;
    }
};