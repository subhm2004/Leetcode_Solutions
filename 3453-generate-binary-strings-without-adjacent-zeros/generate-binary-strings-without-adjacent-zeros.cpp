class Solution {
public:
    void backtrack(int i, int n, string& current, vector<string>& ans) {
        if (i >= n) {
            ans.push_back(current);
            return;
        }

        for (auto& ch : {'1', '0'}) {
            // Skip '0' if last character is also '0'
            if (ch == '0' && !current.empty() && current.back() == '0')
                continue;

            current.push_back(ch);
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
