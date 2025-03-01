class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    long long countVowels(string word) {
        long long total = 0;
        int n = word.size();

        for (int i = 0; i < n; ++i) {
            if (isVowel(word[i]))
                total += 1LL * (i + 1) * (n - i);
        }

        return total;
    }
};
