class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
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