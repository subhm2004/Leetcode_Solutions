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

        string remaining_str;
        while (!st.empty()) {
            remaining_str.push_back(st.top());
            st.pop();
        }
        reverse(remaining_str.begin(), remaining_str.end());

        return {score, remaining_str};
    }

    int maximumGain(string s, int x, int y) {
        string max_str = (x > y) ? "ab" : "ba";
        string min_str = (x > y) ? "ba" : "ab";
        int gain1 = max(x, y);
        int gain2 = min(x, y);

        auto [score1, remaining_str] = helper(s, max_str, gain1);
        auto [score2, _] = helper(remaining_str, min_str, gain2);

        return score1 + score2;
    }
};
