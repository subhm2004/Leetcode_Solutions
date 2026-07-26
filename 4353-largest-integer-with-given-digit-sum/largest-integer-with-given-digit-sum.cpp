class Solution {
public:
    int largestInteger(int n, int s) {
        if (s == 0)
            return 0;

        string ans = "";

        for (int i = 0; i < n; i++) {
            int digit = min(9, s);
            ans += (digit + '0');
            s -= digit;
        }

        if (s > 0)
            return -1;

        return stoi(ans);
    }
};