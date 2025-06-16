class Solution {
public:
    string generateTag(string caption) {
        string tag = "#";
        int n = caption.size();
        bool isFirstWord = true;
        int i = 0;

        while (i < n) {
            // Skip leading spaces
            while (i < n && caption[i] == ' ') i++;

            if (i >= n) break;

            // Build one word
            string word = "";
            while (i < n && caption[i] != ' ') {
                if (isalpha(caption[i])) {
                    word += caption[i];
                }
                i++;
            }

            if (word.empty()) continue;

            // Convert to proper case
            if (isFirstWord) {
                for (char &ch : word) ch = tolower(ch);
                isFirstWord = false;
            } else {
                word[0] = toupper(word[0]);
                for (int j = 1; j < word.size(); ++j) {
                    word[j] = tolower(word[j]);
                }
            }

            tag += word;
        }

        // Truncate if necessary
        if (tag.size() > 100) {
            tag = tag.substr(0, 100);
        }

        return tag;
    }
};
