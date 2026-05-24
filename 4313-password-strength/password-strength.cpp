class Solution {
public:
    int passwordStrength(string password) {

        unordered_set<char> st;

        for (char ch : password) {
            st.insert(ch);
        }

        int score = 0;

        for (char ch : st) {

            if (ch >= 'a' && ch <= 'z') {
                score += 1;
            } else if (ch >= 'A' && ch <= 'Z') {
                score += 2;
            } else if (ch >= '0' && ch <= '9') {
                score += 3;
            } else {
                score += 5;
            }
        }

        return score;
    }
};