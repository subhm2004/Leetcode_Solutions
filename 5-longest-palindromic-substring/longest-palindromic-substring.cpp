class Solution {
public:
    int maxlen = 1, start = 0;
    
    bool solveRE(string& s, int i, int j) {
        if (i >= j) return true;
        
        if (s[i] == s[j] && solveRE(s, i + 1, j - 1)) {
            int currlen = j - i + 1;
            if (currlen > maxlen) {
                maxlen = currlen;
                start = i;
            }
            return true;
        }
        return false;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                solveRE(s, i, j);
            }
        }
        
        return s.substr(start, maxlen);
    }
};
