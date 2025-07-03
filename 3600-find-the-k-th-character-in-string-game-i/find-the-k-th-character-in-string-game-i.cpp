class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            string temp = "";
            for (int i = 0; i < s.size(); i++) {
                // Get the next character cyclically (z -> a)
                char next = (s[i] == 'z') ? 'a' : s[i] + 1;
                temp += next;
            }
            s += temp;
        }
        return s[k - 1];  // 1-based indexing
    }
};
