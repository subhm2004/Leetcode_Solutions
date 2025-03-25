class Solution {
public:
    int solveRE(vector<string>& words, vector<int>& count, vector<int>& score, int index) {
        // Base case: if all words are considered, return 0
        if (index == words.size()) return 0;

        // Option 1: Skip the current word and move to the next
        int maxScore = solveRE(words, count, score, index + 1);

        // Option 2: Try including the current word
        int wordScore = 0;
        bool canUse = true;
        
        // Check if the word can be formed with available letters
        for (char c : words[index]) {
            count[c - 'a']--; // Reduce letter count
            if (count[c - 'a'] < 0) canUse = false; // If any letter is unavailable, mark as false
            wordScore += score[c - 'a']; // Calculate word score
        }

        // If the word is valid, update maxScore
        if (canUse) {
            maxScore = max(maxScore, wordScore + solveRE(words, count, score, index + 1));
        }

        // Backtrack: Restore the letter count after recursion
        for (char c : words[index]) count[c - 'a']++;

        return maxScore;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0); // Letter frequency array
        for (char c : letters)
            count[c - 'a']++; // Count available letters
        
        return solveRE(words, count, score, 0);
    }
};
