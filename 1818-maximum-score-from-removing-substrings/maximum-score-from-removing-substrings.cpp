class Solution {
public:
    int helper(string& s, const string& matchStr, int gain, string& remaining) {
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

        // Build the remaining string after removal
        remaining.clear();
        while (!st.empty()) {
            remaining.push_back(st.top());
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        return score;
    }

    int maximumGain(string s, int x, int y) {
        string max_str = (x > y) ? "ab" : "ba";
        string min_str = (x > y) ? "ba" : "ab";
        int gain1 = max(x, y);
        int gain2 = min(x, y);

        string first_parse;
        int score = helper(s, max_str, gain1, first_parse);

        string second_parse;
        score += helper(first_parse, min_str, gain2, second_parse);

        return score;
    }
};
