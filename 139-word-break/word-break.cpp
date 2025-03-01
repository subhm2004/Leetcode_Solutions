class Solution {
public:
    bool check(vector<string>& wordDict, string& s) {
        for (auto& word : wordDict) {
            if (s == word)
                return true;
        }
        return false;
    }

    bool solveRE(string& s, vector<string>& wordDict, int start) {
        if (start == s.size())
            return true;

        string word = "";
        for (int i = start; i < s.size(); ++i) {
            word += s[i];
            if (check(wordDict, word) && solveRE(s, wordDict, i + 1)) {
                return true;
            }
        }
        return false;
    }

    bool solveME(string& s, vector<string>& wordDict, int start, vector<int>& dp) {
        if (start == s.size())
            return true;
        if (dp[start] != -1)
            return dp[start];

        string word = "";
        for (int i = start; i < s.size(); ++i) {
            word += s[i];
            if (check(wordDict, word) && solveME(s, wordDict, i + 1, dp)) {
                return dp[start] = true;  
            }
        }
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        // return solveRE(s, wordDict, 0);  
        return solveME(s, wordDict, 0, dp);  
    }
};
