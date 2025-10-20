// class Solution {
//  public:
//   bool isAnagram(string s, string t) {
//     sort(s.begin(),s.end());
//     sort(t.begin(),t.end());
//     return s==t;
//   }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0); // For lowercase letters 'a' to 'z'

        for (char c : s) freq[c - 'a']++; // Count letters in s
        for (char c : t) freq[c - 'a']--; // Subtract letters from t

        for (int count : freq) {
            if (count != 0) return false; // If any count is non-zero → not an anagram
        }

        return true; // All counts are zero → valid anagram
    }
};
