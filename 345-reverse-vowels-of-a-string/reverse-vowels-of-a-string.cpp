class Solution {
public:

    bool isVowel(char c) {
        return string("aeiouAEIOU").find(c) != string::npos;
    }

    string reverseVowels(string s) {
        stack<char> st;

        // Push vowels to the stack
        for (char c : s) {
            if (isVowel(c))
                st.push(c);
        }

        // Replace vowels in reverse order
        for (char& c : s) {
            if (isVowel(c)) {
                c = st.top();
                st.pop();
            }
        }

        return s;
    }
};
