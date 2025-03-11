class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1); // Har character ka last index store karne ke liye array
        int maxLength = 0, start = 0;   // `start` window ka left boundary represent karta hai

        for (int end = 0; end < s.length(); ++end) {
            // Agar character pehle bhi aa chuka hai, toh `start` ko aage badhao
            start = max(start, lastIndex[s[end]] + 1);
            lastIndex[s[end]] = end; // Current character ka last index update karo
            maxLength = max(maxLength, end - start + 1); // Maximum length update karo
        }

        return maxLength; // Sabse lamba substring ka length return karo
    }
};
