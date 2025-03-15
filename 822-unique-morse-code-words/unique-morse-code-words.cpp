class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_code{".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                             "--.",  "....", "..",   ".---", "-.-",  ".-..",
                             "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                             "...",  "-",    "..-",  "...-", ".--",  "-..-",
                             "-.--", "--.."};
        unordered_set<string> uniqueCodes;

        for (string& word : words) {
            string code;
            for (char c : word)
                code += morse_code[c - 'a'];
            uniqueCodes.insert(code);
        }
        return uniqueCodes.size();
    }
};
