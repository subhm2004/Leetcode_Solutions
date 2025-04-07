class Solution {
public:
    int similarPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            unordered_set<char> set1(words[i].begin(), words[i].end());
            for (int j = i + 1; j < n; ++j) {
                unordered_set<char> set2(words[j].begin(), words[j].end());
                if (set1 == set2) {
                    count++;
                }
            }
        }

        return count;
    }
};