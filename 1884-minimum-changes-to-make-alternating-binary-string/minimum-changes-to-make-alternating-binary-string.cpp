class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count_1 = 0, count_2 = 0;

        for (int i = 0; i < n; i++) {
            // Pattern 1: starts with '0'
            if (s[i] != (i % 2 == 0 ? '0' : '1')) count_1++;

            // Pattern 2: starts with '1'
            if (s[i] != (i % 2 == 0 ? '1' : '0')) count_2++;
        }

        return min(count_1, count_2);
    }
};
