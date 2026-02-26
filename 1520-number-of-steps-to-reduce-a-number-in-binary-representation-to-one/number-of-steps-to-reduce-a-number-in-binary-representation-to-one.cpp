class Solution {
public:

    // add 1 to binary string
    void add_one(string &s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }

        if (i >= 0) s[i] = '1';
        else s = "1" + s;   // overflow case
    }

    int numSteps(string s) {

        int steps = 0;

        while (s != "1") {

            // even
            if (s.back() == '0') {
                s.pop_back();   // divide by 2
            }
            else { // odd
                add_one(s);
            }

            steps++;
        }

        return steps;
    }
};