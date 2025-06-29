class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
    void backtrack(const string& s, int start, vector<string>& curr,
                   vector<vector<string>>& ans) {
        if (start == s.length()) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < s.length(); ++i)
            if (isPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, curr, ans);
                curr.pop_back();
            }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(s, 0, curr, ans);
        return ans;
    }
};