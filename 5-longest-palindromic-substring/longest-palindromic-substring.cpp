// class Solution {
// public:
//     bool is_palindrome(const string& s, int l, int r) {
//             while (l < r) {
//                 if (s[l++] != s[r--])
//                     return false;
//             }
//             return true;
//         }
//     string longestPalindrome(string s) {
//         int n = s.length();
//         int max_len = 1, start_idx = 0;

//         // Check all substrings s[i..j]
//         for (int i = 0; i < n; ++i) {
//             for (int j = i; j < n; ++j) {
//                 if (is_palindrome(s, i, j)) {
//                     int len = j - i + 1;
//                     if (len > max_len) {
//                         max_len = len;
//                         start_idx = i;
//                     }
//                 }
//             }
//         }

//         return s.substr(start_idx, max_len);
//     }
// };


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
