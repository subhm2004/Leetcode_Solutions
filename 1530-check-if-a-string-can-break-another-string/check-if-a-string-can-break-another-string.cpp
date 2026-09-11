class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int ans_1 = 0, ans_2 = 0;

        int n = s1.size();

        for (int i = 0; i < n; i++) {
            if (s1[i] > s2[i])
                ans_1++;
            else if (s2[i] > s1[i])
                ans_2++;
            else {
                ans_1++;
                ans_2++;
            }
        }
        if (ans_1 == n || ans_2 == n)
            return 1;
        else
            return 0;
    }
};