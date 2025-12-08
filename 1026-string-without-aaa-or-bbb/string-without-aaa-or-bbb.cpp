class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";

        while (a > 0 || b > 0) {
            bool write_a = false;

            if (a > b) {
                write_a = true;
            } else {
                write_a = false;
            }

            int n = s.size();
            if (n >= 2 && s[n - 1] == s[n - 2]) {
                if (s[n - 1] == 'a')
                    write_a = false;
                else
                    write_a = true;
            }

            if (write_a) {
                s.push_back('a');
                a--;
            } else {
                s.push_back('b');
                b--;
            }
        }

        return s;
    }
};
