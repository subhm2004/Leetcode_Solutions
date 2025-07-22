class Solution {
public:
    string reformatNumber(string number) {
        string digits = "";
        for (char c : number) {
            if (isdigit(c)) digits += c;
        }

        string ans = "";
        int i = 0, n = digits.size();

        while (i < n) {
            int remaining = n - i;

            if (remaining > 4) {
                ans += digits.substr(i, 3) + "-";
                i += 3;
            } else if (remaining == 4) {
                ans += digits.substr(i, 2) + "-" + digits.substr(i + 2, 2);
                break;
            } else if (remaining == 3) {
                ans += digits.substr(i, 3);
                break;
            } else if (remaining == 2) {
                ans += digits.substr(i, 2);
                break;
            }
        }

        return ans;
    }
};
