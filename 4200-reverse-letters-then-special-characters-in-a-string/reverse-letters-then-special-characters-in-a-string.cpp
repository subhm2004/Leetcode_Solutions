class Solution {
public:
    bool is_letter(char c) {
        return (c >= 'a' && c <= 'z');
    }

    string reverseByType(string s) {

        int n = s.size();

        // reverse only english letters
        int l = 0, r = n - 1;
        while (l < r) {

            while (l < r && !is_letter(s[l])) l++;
            while (l < r && !is_letter(s[r])) r--;

            if (l < r)
                swap(s[l++], s[r--]);
        }

        // reverse only special characters
        l = 0, r = n - 1;
        while (l < r) {

            while (l < r && is_letter(s[l])) l++;
            while (l < r && is_letter(s[r])) r--;

            if (l < r)
                swap(s[l++], s[r--]);
        }

        return s;
    }
};
