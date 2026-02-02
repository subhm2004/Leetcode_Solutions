class Solution {
public:
    int minMovesToMakePalindrome(string s) {

        int left = 0, right = s.size() - 1;
        int moves = 0;

        // Process string from both ends
        while (left < right) {

            // If already matching, move both pointers
            if (s[left] == s[right]) {
                left++;
                right--;
                continue;
            }

            // Find matching character for s[left] from the right side
            int match_pos = right;
            while (match_pos > left && s[match_pos] != s[left]) {
                match_pos--;
            }

            // If no matching character found on the right
            // then this character must go to the middle
            if (match_pos == left) {
                swap(s[left], s[left + 1]);
                moves++;
                continue;
            }

            // Bring the matching character to position 'right'
            // using adjacent swaps
            while (match_pos < right) {
                swap(s[match_pos], s[match_pos + 1]);
                moves++;
                match_pos++;
            }

            // Current pair is fixed
            left++;
            right--;
        }

        return moves;
    }
};
