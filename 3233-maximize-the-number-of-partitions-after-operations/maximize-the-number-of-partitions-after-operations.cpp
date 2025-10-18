
class Solution {
public:
    unordered_map<long long, int> dp;
    string s;
    int k;

    int solveME(long long i, long long unique_chars, bool can_change) {
        long long key = (i << 27) | (unique_chars << 1) | (can_change);

        if (dp.count(key)) {  
            return dp[key];
        }

        if (i == s.size()) {
            return 1;
        }

        int char_idx = s[i] - 'a';
        int unique_chars_updated = unique_chars | (1 << char_idx);
        int unique_char_count = __builtin_popcount(unique_chars_updated);

        int ans;
        if (unique_char_count > k) {
            ans = 1 + solveME(i + 1, 1 << char_idx, can_change);
        } else {
            ans = solveME(i + 1, unique_chars_updated, can_change);
        }

        if (can_change) {
            for (int new_char_idx = 0; new_char_idx < 26; new_char_idx++) {
                int new_set = unique_chars | (1 << new_char_idx);
                int new_unique_char_count = __builtin_popcount(new_set);

                if (new_unique_char_count > k) {
                    ans = max(ans, 1 + solveME(i + 1, 1 << new_char_idx, false));
                } else {
                    ans = max(ans, solveME(i + 1, new_set, false));
                }
            }
        }

        return dp[key] = ans;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        this->s = s;
        this->k = k;
        return solveME(0, 0, true) ;
    }
};