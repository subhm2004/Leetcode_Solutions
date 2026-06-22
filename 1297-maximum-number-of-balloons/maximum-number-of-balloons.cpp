class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};
        
        // Step 1: count frequency of each character in text
        for (char c : text) {
            freq[c - 'a']++;
        }
        
        // Step 2: "balloon" needs -> b:1, a:1, l:2, o:2, n:1
        int b = freq['b' - 'a'];
        int a = freq['a' - 'a'];
        int l = freq['l' - 'a'] / 2;
        int o = freq['o' - 'a'] / 2;
        int n = freq['n' - 'a'];
        
        // Step 3: answer is the minimum across all
        return min({b, a, l, o, n});
    }
};