class Solution {
public:
    // Helper: ek frequency vector me se find krega kitne unique elements hai
    int countDistinct(const vector<int>& freq) {
        int count = 0;
        for (int f : freq) {
            if (f > 0) count++;
        }
        return count;
    }

    bool isItPossible(string word1, string word2) {
        vector<int> freq1(26, 0), freq2(26, 0);

        for (char c : word1) freq1[c - 'a']++;
        for (char c : word2) freq2[c - 'a']++;

        // Try all character swaps from word1 and word2
        for (int i = 0; i < 26; ++i) {
            if (freq1[i] == 0) continue;

            for (int j = 0; j < 26; ++j) {
                if (freq2[j] == 0) continue;

                vector<int> t1 = freq1, t2 = freq2;

                // Simulate swap: word1[i] with word2[j] [ ek tarike se swaping hi ki hai ]
                t1[i]--; t1[j]++;
                t2[j]--; t2[i]++;

                if ( countDistinct(t1) == countDistinct(t2)) return true;
            }
        }

        return false;
    }
};
