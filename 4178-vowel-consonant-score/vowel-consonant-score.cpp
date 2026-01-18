class Solution {
public:
    bool is_vowel(char ch) {
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                if (is_vowel(ch)) v++;
                else c++;
            }
        }

        if (c == 0) return 0;
        return floor(v / c);
    }
};