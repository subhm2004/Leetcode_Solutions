class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> count(26, 0);

        for (char c : s) 
            count[c - 'a']++; // Count occurrences

        int freq = count[s[0] - 'a']; // Get frequency of first character

        for (int f : count) 
            if (f > 0 && f != freq) 
                return false; // Check if all nonzero frequencies are the same

        return true;
    }
};
