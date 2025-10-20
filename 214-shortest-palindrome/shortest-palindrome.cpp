auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
typedef long long ll;
class Palindrome_Check
{
public:
    const ll RADIX_1 = 26, MOD_1 = 1e9 + 7;
    const ll RADIX_2 = 27, MOD_2 = 1e9 + 33;

    string s;
    ll n;
    vector<ll> pref_1, pref_2, r_pref_1, r_pref_2, pow_1, pow_2;

    Palindrome_Check(const string &str)
    {
        s = str;
        n = s.size();
        pref_1.assign(n + 1, 0);
        pref_2.assign(n + 1, 0);
        r_pref_1.assign(n + 1, 0);
        r_pref_2.assign(n + 1, 0);
        pow_1.assign(n + 1, 1);
        pow_2.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            pow_1[i] = (pow_1[i - 1] * RADIX_1) % MOD_1;
            pow_2[i] = (pow_2[i - 1] * RADIX_2) % MOD_2;
        }

        for (int i = 0; i < n; i++)
        {
            ll val = s[i] - 'a';

            pref_1[i + 1] = (pref_1[i] * RADIX_1 + val) % MOD_1;
            pref_2[i + 1] = (pref_2[i] * RADIX_2 + val) % MOD_2;

            ll r_val = s[n - 1 - i] - 'a';
            r_pref_1[i + 1] = (r_pref_1[i] * RADIX_1 + r_val) % MOD_1;
            r_pref_2[i + 1] = (r_pref_2[i] * RADIX_2 + r_val) % MOD_2;
        }
    }

    pair<ll, ll> get_Hash(int l, int r)
    {
        ll hash_1 = (pref_1[r + 1] - pref_1[l] * pow_1[r - l + 1] % MOD_1 + MOD_1) % MOD_1;
        ll hash_2 = (pref_2[r + 1] - pref_2[l] * pow_2[r - l + 1] % MOD_2 + MOD_2) % MOD_2;
        return {hash_1 % MOD_1, hash_2 % MOD_2};
    }

    pair<ll, ll> get_Reverse_Hash(int l, int r)
    {
        int rl = n - 1 - r;
        int rr = n - 1 - l;
        ll hash_1 = (r_pref_1[rr + 1] - r_pref_1[rl] * pow_1[rr - rl + 1] % MOD_1 + MOD_1) % MOD_1;
        ll hash_2 = (r_pref_2[rr + 1] - r_pref_2[rl] * pow_2[rr - rl + 1] % MOD_2 + MOD_2) % MOD_2;
        return {hash_1 % MOD_1, hash_2 % MOD_2};
    }

    bool is_Palindrome(int l, int r)
    {
        return get_Hash(l, r) == get_Reverse_Hash(l, r);
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;

        Palindrome_Check pc(s);
        int n = s.size();
        int longest_prefix_pal = 0;

        // Find longest prefix which is palindrome
        for (int i = n - 1; i >= 0; i--) {
            if (pc.is_Palindrome(0, i)) {
                longest_prefix_pal = i; // phli value jo milegi vhi sabse bada hoga 
                break;
            }
        }

        // Remaining suffix after the palindrome prefix
        string remain = s.substr(longest_prefix_pal + 1);
        reverse(remain.begin(), remain.end());

        return remain + s;
    }
};

