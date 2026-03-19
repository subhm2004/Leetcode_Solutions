class Solution {
public:
    int strStr(string str, string pattern) {
        int m = str.length();
        int n = pattern.length();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (str[i + j] != pattern[j]) {
                    break;
                }
                if (j == n - 1)
                    return i;
            }
        }
        return -1;
    }
};