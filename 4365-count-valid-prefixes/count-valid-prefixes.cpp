class Solution {
public:
    int countValidPrefixes(string s) {

        int zero = 0, one = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '0')
                zero++;
            else
                one++;

            if (abs(zero - one) <= 1)
                ans++;
        }

        return ans;
    }
};