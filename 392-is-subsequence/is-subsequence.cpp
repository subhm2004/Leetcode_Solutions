class Solution {
public:
    bool check_subsequence(const string& s, const string& t, int i, int j) {
        if (i == s.size() || j == t.size())
            return i == s.size();

        return (s[i] == t[j]) ? check_subsequence(s, t, i + 1, j + 1)
                              : check_subsequence(s, t, i, j + 1);
    }
    bool isSubsequence(string s, string t) {
        return check_subsequence(s, t, 0, 0);
    }
};