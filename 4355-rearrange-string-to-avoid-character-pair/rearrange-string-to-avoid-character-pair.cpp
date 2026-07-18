class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int count_x = 0, count_y = 0;
        string other = "";

        for (char ch : s) {
            if (ch == x)
                count_x++;
            else if (ch == y)
                count_y++;
            else
                other += ch;
        }

        string ans = "";

        while (count_y--)
            ans += y;


        while (count_x--)
            ans += x;

         ans += other;


        return ans;
    }
};