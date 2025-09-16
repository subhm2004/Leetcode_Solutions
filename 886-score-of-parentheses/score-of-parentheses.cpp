class Solution {
public:
    int helper(string &s, int &i) {
        int score = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                i++;  // skip '('
                int inner = helper(s, i); // andar ka score nikaalo
                score += max(2 * inner, 1); 
            } else {
                i++;  // skip ')'
                return score;
            }
        }
        return score;
    }

    int scoreOfParentheses(string s) {
        int i = 0;
        return helper(s, i);
    }
};