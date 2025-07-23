class Solution {
public:
    pair<int, string> helper(const string& s, const string& matchStr, int gain) {
        stack<char> st;
        int score = 0;

        for (char ch : s) {
            if (!st.empty() && st.top() == matchStr[0] && ch == matchStr[1]) {
                st.pop();
                score += gain;
            } else {
                st.push(ch);
            }
        }

        string remaining;
        while (!st.empty()) {
            remaining.push_back(st.top());
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        return {score, remaining};
    }

    int maximumGain(string s, int x, int y) {
        string max_str = (x > y) ? "ab" : "ba";
        string min_str = (x > y) ? "ba" : "ab";
        int gain1 = max(x, y);
        int gain2 = min(x, y);

        auto [score1, remaining1] = helper(s, max_str, gain1);
        auto [score2, _] = helper(remaining1, min_str, gain2);

        return score1 + score2;
    }
};
