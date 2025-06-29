class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
            while (l < r) {
                if (s[l++] != s[r--])
                    return false;
            }
            return true;
        }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = 1, start = 0;

        // Check all substrings s[i..j]
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPalindrome(s, i, j)) {
                    int len = j - i + 1;
                    if (len > maxlen) {
                        maxlen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxlen);
    }
};
