class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        
        char startCol = s[0]; // shuru ka column letter, jaise 'A'
        char endCol = s[3];   // end wala column letter, jaise 'C'
        char startRow = s[1]; // shuru ka row number (character), jaise '1'
        char endRow = s[4];   // end wala row number (character), jaise '3'

        // loop chalaye columns ke liye startCol se leke endCol tak
        for (char col = startCol; col <= endCol; ++col) {
            // har column ke andar rows ke liye loop chalayen startRow se endRow tak
            for (char row = startRow; row <= endRow; ++row) {
                // har combination ko string banake ans mein daal do, jaise "A1"
                ans.push_back(string(1, col) + row);
            }
        }
        return ans;
    }
};
