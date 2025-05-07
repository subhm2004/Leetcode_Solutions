class Solution {
public:
    void backtrack(int i, int n, string& current, vector<string>& ans) {
        if (i >= n) {
            ans.push_back(current);
            return;
        }

        // Always safe to add '1'
        current.push_back('1');
        backtrack(i + 1, n, current, ans);
        current.pop_back();

        // Safe to add '0' only if previous character is not '0'
        if (i == 0 || current.back() != '0') {
            current.push_back('0');
            backtrack(i + 1, n, current, ans);
            current.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string current;
        backtrack(0, n, current, ans);
        return ans;
    }
};
