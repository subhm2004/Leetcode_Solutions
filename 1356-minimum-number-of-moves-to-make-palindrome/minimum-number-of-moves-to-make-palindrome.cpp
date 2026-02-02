class Solution {
public:
    int minMovesToMakePalindrome(string s) {

        int n = s.size();
        int l = 0, r = n - 1;
        int ans = 0;

        while (l < r) {

            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            }

            int k = r;

            while (k > l && s[k] != s[l]) k--;

            // s[l] is the middle character
            if (k == l) {
                swap(s[l], s[l + 1]);
                ans++;
            }
            else {
                // bring s[k] to position r
                while (k < r) {
                    swap(s[k], s[k + 1]);
                    ans++;
                    k++;
                }
                l++;
                r--;
            }
        }

        return ans;
    }
};
