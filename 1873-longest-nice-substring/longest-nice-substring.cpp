class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string result = "";
        
        for (int i = 0; i < n; i++) {
            unordered_set<char> lower, upper;
            for (int j = i; j < n; j++) {
                char c = s[j];
                if (islower(c)) lower.insert(c);
                else upper.insert(c);
                
                // Check if current substring is nice
                bool nice = true;
                for (char ch : lower) {
                    if (upper.find(toupper(ch)) == upper.end()) {
                        nice = false;
                        break;
                    }
                }
                for (char ch : upper) {
                    if (lower.find(tolower(ch)) == lower.end()) {
                        nice = false;
                        break;
                    }
                }
                
                if (nice && j - i + 1 > result.size()) {
                    result = s.substr(i, j - i + 1);
                }
            }
        }
        
        return result;
    }
};
