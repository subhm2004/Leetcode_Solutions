class Solution {
public:
    void solveRE(vector<string>& ans, int open, int close, string output) {
        if (open == 0 && close == 0) {
            ans.push_back(output);
            return;
        }
        if (open > 0) {
            solveRE(ans, open - 1, close, output + '(');
        }
        if (close > open) {
            solveRE(ans, open, close - 1, output + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solveRE(ans, n, n, "");
        return ans;
    }
};
