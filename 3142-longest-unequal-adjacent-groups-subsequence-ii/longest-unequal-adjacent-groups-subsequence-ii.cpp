class Solution {
public:
    int hamming_Distance(const string& a, const string& b) {
        if (a.length() != b.length()) return -1;
        int dist = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] != b[i]) dist++;
        return dist;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int maxLength = 1;
        int lastIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] &&
                    words[i].length() == words[j].length() &&
                    hamming_Distance(words[i], words[j]) == 1) {

                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        vector<string> ans;
        while (lastIndex != -1) {
            ans.push_back(words[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
