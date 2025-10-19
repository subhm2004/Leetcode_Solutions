// Rabin Karp Algorithm - Double Hashing  TC :- O(m+n)
typedef long long ll;
class Solution {
public:
    const ll RADIX_1 = 26;
    const ll MOD_1 = 1e9 + 7;
    const ll RADIX_2 = 27;
    const ll MOD_2 = 1e9 + 33;

    pair<ll, ll> hash_pair(string str, ll m) {
        ll hash_1 = 0, hash_2 = 0;
        ll factor_1 = 1, factor_2 = 1;
        for (ll i = m - 1; i >= 0; i--) {
            hash_1 += ((str[i] - 'a') * factor_1) % MOD_1;
            factor_1 = (factor_1 * RADIX_1) % MOD_1;
            hash_2 += ((str[i] - 'a') * factor_2) % MOD_2;
            factor_2 = (factor_2 * RADIX_2) % MOD_2;
        }
        return {hash_1 % MOD_1, hash_2 % MOD_2};
    }
    int strStr(string haystack, string needle) {
        ll n = haystack.size();
        ll m = needle.size();
        if(n < m) return -1;

        ll MAX_WEIGHT_1 = 1, MAX_WEIGHT_2 = 1;
        for (ll i = 0; i < m; i++) {
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        }
        pair<ll, ll> hash_needle = hash_pair(needle, m);
        pair<ll, ll> hash_hey = {0, 0};

        for (ll i = 0; i <= n - m; i++) {
            if (i == 0) {
                hash_hey = hash_pair(haystack, m);
            } else {
                hash_hey.first = ((hash_hey.first * RADIX_1) % MOD_1 - ((haystack[i - 1] - 'a') * MAX_WEIGHT_1) % MOD_1 + (haystack[i + m - 1] - 'a') + MOD_1) % MOD_1;

                hash_hey.second = ((hash_hey.second * RADIX_2) % MOD_2 - ((haystack[i - 1] - 'a') * MAX_WEIGHT_2) % MOD_2 + (haystack[i + m - 1] - 'a') + MOD_2) % MOD_2;
            }
            if(hash_needle.first == hash_hey.first && hash_needle.second == hash_hey.second){
                return i;
            }
        }
        return -1;
    }
};