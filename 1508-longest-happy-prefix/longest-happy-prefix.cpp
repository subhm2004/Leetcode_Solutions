// Rabin Karp Algorithm - Double Hashing  TC: O(n)
typedef long long ll;
class Solution {
public:
    const ll RADIX_1 = 26;
    const ll MOD_1 = 1e9 + 7;
    const ll RADIX_2 = 27;
    const ll MOD_2 = 1e9 + 33;

    string longestPrefix(string s) {
        ll n = s.size();
        if(n <= 1) return "";

        pair<ll, ll> hash_prefix = {0, 0};
        pair<ll, ll> hash_suffix = {0, 0};
        ll power_1 = 1, power_2 = 1;
        ll max_len = 0;

        for (ll len = 1; len < n; len++) {
            // Rolling prefix hash (add character at the end)
            hash_prefix.first = ((hash_prefix.first * RADIX_1) % MOD_1 + (s[len - 1] - 'a')) % MOD_1;
            hash_prefix.second = ((hash_prefix.second * RADIX_2) % MOD_2 + (s[len - 1] - 'a')) % MOD_2;

            // Rolling suffix hash (add character at the beginning)
            hash_suffix.first = (hash_suffix.first + ((s[n - len] - 'a') * power_1) % MOD_1) % MOD_1;
            hash_suffix.second = (hash_suffix.second + ((s[n - len] - 'a') * power_2) % MOD_2) % MOD_2;

            if (hash_prefix.first == hash_suffix.first && hash_prefix.second == hash_suffix.second) {
                max_len = len;
            }

            power_1 = (power_1 * RADIX_1) % MOD_1;
            power_2 = (power_2 * RADIX_2) % MOD_2;
        }

        return s.substr(0, max_len);
    }
};