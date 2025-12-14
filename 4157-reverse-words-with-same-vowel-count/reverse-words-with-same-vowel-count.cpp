class Solution {
public:
    bool is_vowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int count_vowels(const string& word) {
        int count = 0;
        for (char c : word) {
            if (is_vowel(c)) count++;
        }
        return count;
    }

    string reverseWords(string s) {
        vector<string> words;
        string curr_str;

        // string into words
        for (char c : s) {
            if (c == ' ') {
                words.push_back(curr_str);
                curr_str.clear();
            } else {
                curr_str += c;
            }
        }
        words.push_back(curr_str); // last word

         int first_vowels = count_vowels(words[0]);

         for (int i = 1; i < words.size(); i++) {
            if (count_vowels(words[i]) == first_vowels) {
                reverse(words[i].begin(), words[i].end());
            }
        }

         string ans;
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i + 1 < words.size()) ans += ' ';
        }

        return ans;
    }
};
