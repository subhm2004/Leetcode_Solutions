class Solution {
public:
    int minMovesToMakePalindrome(string s) {

        int n = s.size();
        int left = 0, right = n - 1;
        int ans = 0;

        while (left < right) {

            int l = left;
            int r = right;

            // find matching character for s[l] from the right side
            while (l < r && s[l] != s[r])
                r--;

            // no matching character found (this is the middle one)
            if (l == r) {
                swap(s[r], s[r + 1]);
                ans++;
                continue;
            }
            else {
                // bring s[r] to position 'right'
                while (r < right) {
                    swap(s[r], s[r + 1]);
                    ans++;
                    r++;
                }
            }

            left++;
            right--;
        }

        return ans;
    }
};
