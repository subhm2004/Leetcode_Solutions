class Solution {
public:
    static const int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> charCount(26, 0);

        for (char ch : s) {
            charCount[ch - 'a']++;
        }

        for (int step = 0; step < t; ++step) {
            vector<long long> newCharCount(26, 0);

            for (int i = 0; i < 26; ++i) {
                if (i == 25) {
                    newCharCount[0] = (newCharCount[0] + charCount[i]) % MOD;
                    newCharCount[1] = (newCharCount[1] + charCount[i]) % MOD;
                } else {
                    newCharCount[i + 1] =
                        (newCharCount[i + 1] + charCount[i]) % MOD;
                }
            }

            charCount = newCharCount;
        }

        long long totalLength = 0;
        for (long long count : charCount) {
            totalLength = (totalLength + count) % MOD;
        }

        return totalLength;
    }
};
