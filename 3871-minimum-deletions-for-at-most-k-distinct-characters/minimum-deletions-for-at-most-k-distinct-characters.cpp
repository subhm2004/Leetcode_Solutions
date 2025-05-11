class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> freq(26, 0);

        // Step 1: Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: Get frequencies of present characters
        vector<int> presentFreqs;
        for (int f : freq) {
            if (f > 0)
                presentFreqs.push_back(f);
        }

        int distinct = presentFreqs.size();
        if (distinct <= k)
            return 0;

        // Step 3: Sort to remove least frequent characters
        sort(presentFreqs.begin(), presentFreqs.end());

        int deletions = 0;
        int toDelete = distinct - k;

        for (int i = 0; i < toDelete; ++i) {
            deletions += presentFreqs[i];  // delete whole character
        }

        return deletions;
    }
};
