class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int freqS[26] = {0};
        int freqT[26] = {0};
        
        // Step 1: count characters in s
        for (char c : s) {
            freqS[c - 'a']++;
        }
        
        // Step 2: count characters in target
        for (char c : target) {
            freqT[c - 'a']++;
        }
        
        // Step 3: find minimum ratio across chars present in target
        int result = INT_MAX;
        
        for (int i = 0; i < 26; i++) {
            if (freqT[i] > 0) {
                result = min(result, freqS[i] / freqT[i]);
            }
        }
        
        return result;
    }
};