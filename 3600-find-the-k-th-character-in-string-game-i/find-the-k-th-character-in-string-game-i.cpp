class Solution {
public:
    char nextChar(char ch) {
            return (ch == 'z') ? 'a' : ch + 1;
        }

    char getCharAt(int k, int length) {
            if (k == 1) return 'a';

            int half = length / 2;

            if (k <= half) {
                return getCharAt(k, half);
            } else {
                // The second half is transformed version of first half
                char ch = getCharAt(k - half, half);
                return nextChar(ch);
            }
        }

    char kthCharacter(int k) {
        string word = "a";
        int length = 1;

        // Step 1: Find how many rounds we need until length >= k
        while (length < k) {
            length *= 2;
        }

        return getCharAt(k, length);
    }

};
