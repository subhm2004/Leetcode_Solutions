class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool is_consonant(char c) {
    return (c >= 'a' && c <= 'z') && !is_vowel(c);
}
    int maxVowels(string s, int k) {
        int n = s.size();
        int count = 0, max_count = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (is_vowel(s[right]))
                count++;

            // shrinking the window size if it exceeds k
            if (right - left + 1 > k) {
                if (is_vowel(s[left]))
                    count--;
                left++;
            }

            if (right - left + 1 == k) {
                max_count = max(max_count, count);
            }
        }
        return max_count;
    }
};


/*

class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        
        int n = s.size();
        int count = 0, maxCount = 0;
        
        // Initial window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) count++;
        }
        maxCount = count;
        
        // Slide window
        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) count++;       // add new char
            if (isVowel(s[i - k])) count--;   // remove old char
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};



*/