class Solution {
public:
    bool are_Consecutive(char c1, char c2) {
        int diff = abs(c1 - c2);
        return diff == 1 || diff == 25;
    }

    string resultingString(string s) {
        stack<char> st;

        for (char &c : s) {
            if (!st.empty() && are_Consecutive(st.top(), c)) {
                st.pop(); // remove the pair
            } else {
                st.push(c);
            }
        }

        // Build the ans from stack (reverse order)
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
