class Solution {
public:
    // Expand from the center and return length of palindrome
    int expand_around_center(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // Length of palindrome
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            int len1 = expand_around_center(s, i, i);     // Odd length
            int len2 = expand_around_center(s, i, i + 1); // Even length
            int len = max(len1, len2);

            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
