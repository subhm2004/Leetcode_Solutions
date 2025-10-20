typedef long long ll;
class Solution {
public:
    string shortestPalindrome(string s) {
        const ll RADIX = 26;
        const ll MOD = 1e9 + 7;
        int n = s.size();
        if (n == 0) return s;

        vector<ll> prefix(n + 1, 0);   // prefix[0] = 0 for empty string
        vector<ll> r_prefix(n + 1, 0); // reverse prefix hash
        vector<ll> power(n + 1, 1);    // RADIX ke powers store karne ke liye

        // RADIX ke powers precompute kar rahe hain
        for (int i = 1; i <= n; i++)
            power[i] = (power[i - 1] * RADIX) % MOD;

        int longest_pal_prefix = 0; // palindrome prefix ka last char ka index (0-based)

        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a'; // 0-based mapping: 'a'->0, 'b'->1, ...

            // Forward hash: s[0..i] ka hash
            prefix[i + 1] = (prefix[i] * RADIX + val) % MOD;

            // Reverse prefix hash: reversed s[0..i] ka hash
            r_prefix[i + 1] = (r_prefix[i] + val * power[i]) % MOD;

            // Check kar rahe hain agar prefix s[0..i] palindrome hai
            if (prefix[i + 1] == r_prefix[i + 1]) {
                longest_pal_prefix = i; // 0-based index update
            }
        }

        // Palindrome prefix ke baad ka remaining part
        string remain = s.substr(longest_pal_prefix + 1);
        reverse(remain.begin(), remain.end()); // suffix ko reverse kar ke prepend karenge

        return remain + s; // shortest palindrome return karenge
    }
};
