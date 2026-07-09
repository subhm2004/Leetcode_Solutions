class Solution {
public:
    int minOperations(string s1, string s2) {

        int n = s1.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (s1[i] == s2[i])
                continue;

            // 0 -> 1
            if (s1[i] == '0') {
                s1[i] = '1';
                ans++;
                continue;
            }

            // 1 -> 0

            // Pair with right 1
            if (i + 1 < n && s1[i + 1] == '1') {
                s1[i] = '0';
                s1[i + 1] = '0';
                ans++;
                continue;
            }

            // Pair with left 1
            if (i - 1 >= 0 && s1[i - 1] == '1') {
                s1[i] = s2[i];
                ans++;

                if (s2[i - 1] == '1')
                    ans++;

                s1[i - 1] = s2[i - 1];
                continue;
            }

            // Create right 1 first
            if (i + 1 < n && s1[i + 1] == '0') {
                s1[i] = s2[i];
                ans += 2;

                if (s2[i + 1] == '1')
                    ans++;

                s1[i + 1] = s2[i + 1];
                continue;
            }

            // Create left 1 first
            if (i - 1 >= 0 && s1[i - 1] == '0') {
                s1[i] = s2[i];
                ans += 2;

                if (s2[i - 1] == '1')
                    ans++;

                s1[i - 1] = s2[i - 1];
                continue;
            }

            return -1;
        }

        return (s1 == s2 ? ans : -1);
    }
};