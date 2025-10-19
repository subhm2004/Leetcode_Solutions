class Solution {
public:
    void compute_LPS(const string &s, vector<int>& lps) {
        int length = 0;
        lps[0] = 0;
        int i = 1;
        while (i < s.size()) {
            if (s[i] == s[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    string longestPrefix(string s) {
        int n = s.size();
        if (n <= 1) return "";

        vector<int> lps(n);
        compute_LPS(s, lps);

        int len = lps[n - 1]; // longest happy prefix length
        return s.substr(0, len);
    }
};
