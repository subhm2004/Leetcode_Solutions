class Solution {
public:
    int helper(string &s, int &i) {
        int score = 0;

        while (i < s.size()) {
            if (s[i] == '(') {
                i++;  // '(' skip kar diya
                int inner = helper(s, i);  // andar ka score nikaal lo
                // agar "()" mila to inner = 0 hoga → score += 1
                // agar "(A)" mila to score += 2 * A
                score += (inner == 0 ? 1 : 2 * inner);
            } else {
                i++;  // ')' skip
                return score; // ek block complete ho gaya
            }
        }

        return score;
    }

    int scoreOfParentheses(string s) {
        int i = 0;
        return helper(s, i);
    }
};