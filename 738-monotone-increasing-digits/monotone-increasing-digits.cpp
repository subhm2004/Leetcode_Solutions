class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int m = s.size();
        int mark ;

        // Traverse from right to left
        for (int i = m - 1; i > 0; i--) {
            if (s[i] < s[i - 1]) {
                s[i - 1]--;  // decrease
                mark = i;    // mark position
            }
        }

        // Fill all digits after mark with 9
        for (int i = mark; i < m; i++) {
            s[i] = '9';
        }

        return stoi(s);
    }
};
