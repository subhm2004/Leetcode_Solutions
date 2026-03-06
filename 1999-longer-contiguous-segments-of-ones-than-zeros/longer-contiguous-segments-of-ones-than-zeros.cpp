class Solution {
public:
    int solve(string& s, char ch) {

        int count = 1;
        int max_len = (s[0] == ch ? 1 : 0);

        for (int i = 1; i < s.size(); i++) {

            if (s[i] == s[i - 1])
                count++;
            else
                count = 1;

            if (s[i] == ch)
                max_len = max(max_len, count);
        }

        return max_len;
    }
    bool checkZeroOnes(string s) {
        int longest1 = solve(s, '1');
        int longest0 = solve(s, '0');

        return longest1 > longest0;
    }
};