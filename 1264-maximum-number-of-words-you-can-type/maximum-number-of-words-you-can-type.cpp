class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // 26 size ka array banaya to mark broken letters
        vector<bool> broken(26, false);
        for (char c : brokenLetters) broken[c - 'a'] = true;

        int count = 0;       // kitne words type ho paayenge
        bool can_type = true; // current word type ho sakta hai ya nahi

        // pura string traverse karenge
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') { 
                // agar space ya string ka end mil gaya -> word khatam
                if (can_type) count++;   // agar word me koi broken letter nahi mila to count++
                can_type = true;         // next word ke liye reset kar diya
            } else {
                // agar current character broken letter hai
                if (broken[text[i] - 'a']) {
                    can_type = false;    // is word ko type nahi kar sakte
                }
            }
        }

        return count; // total words jo type ho sakte hain
    }
};
