class Solution {
public:

    // Step 1: LPS (Longest Prefix Suffix) array banate hain
    void compute_LPS(string pattern, vector<int>& lps) {
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < pattern.length()) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Step 2: strStr using KMP
    int strStr(string &text, string &pattern) {
        if (pattern.empty()) return 0;  // Edge case: empty pattern

        int n = text.length();
        int m = pattern.length();
        vector<int> lps(m, 0);

        compute_LPS(pattern, lps); // LPS array banao

        int i = 0, j = 0;

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j; // pehla match mila
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1; // match nahi mila
    }
};
