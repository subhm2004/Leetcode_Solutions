class Solution {
public:
    unordered_map<long long, int> dp;
    string S;
    int K;
        
    int solveME(long long i, long long unique_chars, bool can_change) {
        long long key = (i << 27) | (unique_chars << 1) | (can_change);
        /*
        i << 27: Left-shifting i by 27 bits. This is done to occupy the most significant bits with the value of i.
        unique_chars << 1: Left-shifting unique_chars by 1 bit. 
                          This is done to make space for the least significant bit, 
                          which will be used to represent the boolean value of can_change.
        can_change: This boolean value is ORed with the ans of the left-shift operations.
        */

        if (dp.count(key)) {  // Replaced cache with dp
            return dp[key];
        }

        if (i == S.size()) {
            return 0;
        }

        int character_idx = S[i] - 'a';
        int unique_chars_updated = unique_chars | (1 << character_idx);
        int unique_char_count = __builtin_popcount(unique_chars_updated);

        int ans;
        if (unique_char_count > K) {
            ans = 1 + solveME(i + 1, 1 << character_idx, can_change);
        } else {
            ans = solveME(i + 1, unique_chars_updated, can_change);
        }

        if (can_change) {
            for (int new_char_idx = 0; new_char_idx < 26; new_char_idx++) {
                int new_set = unique_chars | (1 << new_char_idx);
                int new_unique_char_count = __builtin_popcount(new_set);

                if (new_unique_char_count > K) {
                    ans = max(ans, 1 + solveME(i + 1, 1 << new_char_idx, false));
                } else {
                    ans = max(ans, solveME(i + 1, new_set, false));
                }
            }
        }

        return dp[key] = ans;
    }
    
    int maxPartitionsAfterOperations(string s, int k) {
        S = s;
        K = k;
        return solveME(0, 0, true) + 1;
    }
};
