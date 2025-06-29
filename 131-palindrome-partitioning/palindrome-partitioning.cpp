class Solution {     // partition dp + backtracking 
public:
     bool isPalindrome(const string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }

     void backtrack(const string& s, int i, vector<string>& curr,
                   vector<vector<string>>& ans) {
        if (i == s.length()) {
            ans.push_back(curr);   
            return;
        }

        for (int j = i; j < s.length(); ++j)
            if (isPalindrome(s, i, j)) {
                curr.push_back(s.substr(i, j - i + 1));
                backtrack(s, j + 1, curr, ans);
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