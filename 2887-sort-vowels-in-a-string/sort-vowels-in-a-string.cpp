class Solution {
public:
    string sortVowels(string s) {

        string str;
        for (auto c : s) {
            char ch = tolower(c);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                str.push_back(c);
            }
        }
        sort(str.begin(), str.end());
        for (int i = 0, j = 0; i < s.size(); ++i) {
            char ch = tolower(s[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                s[i] = str[j++];
            }
        }
        return s;
    }
};