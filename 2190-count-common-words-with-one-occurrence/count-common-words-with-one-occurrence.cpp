class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> count1, count2;

        // Count occurrences in words1
        for (auto &w : words1) count1[w]++;
        
        // Count occurrences in words2
        for (auto &w : words2) count2[w]++;

        int ans = 0;
        for (auto &[word, cnt] : count1) {
            if (cnt == 1 && count2[word] == 1) {
                ans++;
            }
        }
        return ans;
    }
};