class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi_words = 0;

        for (string& s : sentences) {
            int count = 1;  
            for (char c : s) {
                if (c == ' ')
                    count++;
            }
            maxi_words = max(maxi_words, count);
        }

        return maxi_words;
    }
};
