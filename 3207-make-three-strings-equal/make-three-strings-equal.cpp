class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if (s1[0] != s2[0] || s2[0] != s3[0])
            return -1;

        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        int common_prefix_len = 0;

        while (common_prefix_len < n1 && common_prefix_len < n2 &&
               common_prefix_len < n3 &&
               s1[common_prefix_len] == s2[common_prefix_len] &&
               s2[common_prefix_len] == s3[common_prefix_len]) {
            common_prefix_len++;
        }

        return (n1 - common_prefix_len) + (n2 - common_prefix_len) +
               (n3 - common_prefix_len);
    }
};
