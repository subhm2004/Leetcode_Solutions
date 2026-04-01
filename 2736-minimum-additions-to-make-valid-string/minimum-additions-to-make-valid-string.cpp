class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int i = 0;
        int insertions = 0;

        while (i < n) {
            
            // expect 'a'
            if (i < n && word[i] == 'a') {
                i++;
            } else {
                insertions++;
            }

            // expect 'b'
            if (i < n && word[i] == 'b') {
                i++;
            } else {
                insertions++;
            }

            // expect 'c'
            if (i < n && word[i] == 'c') {
                i++;
            } else {
                insertions++;
            }
        }

        return insertions;
    }
};