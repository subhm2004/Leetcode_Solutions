class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        int moves = 0;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
                continue;
            }

            int match_pos = right;
            while (match_pos > left && s[match_pos] != s[left]) {
                match_pos--;
            }

            if (match_pos == left) {
                swap(s[left], s[left + 1]);
                moves++;
                continue;
            }

            while (match_pos < right) {
                swap(s[match_pos], s[match_pos + 1]);
                moves++;
                match_pos++;
            }

            left++;
            right--;
        }

        return moves;
    }
};

