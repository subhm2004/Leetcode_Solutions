class Solution {
public:
    int hamming_Distance(const string& a, const string& b) {
        if (a.length() != b.length()) return -1;
        int distance = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] != b[i]) distance++;
        return distance;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int max_Length = 1;
        int last_Index = 0;

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
            if (dp[i] > max_Length) {
                max_Length = dp[i];
                last_Index = i;
            }
        }

        vector<string> ans;
        while (last_Index != -1) {
            ans.push_back(words[last_Index]);
            last_Index = prev[last_Index];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
