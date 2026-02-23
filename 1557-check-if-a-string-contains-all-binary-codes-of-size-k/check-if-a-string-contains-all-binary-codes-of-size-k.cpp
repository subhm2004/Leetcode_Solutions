typedef long long ll;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        ll n = s.size();
        if (k > n) return false;

        const ll RADIX = 2;
        const ll MOD = 1e9 + 7;

        ll hash_val = 0;
        ll MAX_WEIGHT = 1;  // RADIX^k

        // compute RADIX^k % MOD
        for (int i = 0; i < k; i++)
            MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;

        // calculate hash of first window of size k
        for (int i = 0; i < k; i++)
            hash_val = (hash_val * RADIX + (s[i] - '0')) % MOD;

        unordered_set<ll> seen;
        seen.insert(hash_val);

        // slide window across the string
        for (int i = k; i < n; i++) {
            ll old_char = (s[i - k] - '0');
            ll new_char = (s[i] - '0');

            hash_val = (hash_val * RADIX - (old_char * MAX_WEIGHT) % MOD + new_char + MOD) % MOD;
            seen.insert(hash_val);
        }

        return seen.size() == (1LL << k);
    }
};

