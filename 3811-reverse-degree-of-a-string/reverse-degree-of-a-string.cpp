class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int reversePos = 27 - (s[i] - 'a' + 1);  // Compute reversed alphabet position
            // int reversePos = 'z' - s[i] + 1;

            ans += reversePos * (i + 1);  // Multiply with 1-based index
        }
        return ans;
    }
};
