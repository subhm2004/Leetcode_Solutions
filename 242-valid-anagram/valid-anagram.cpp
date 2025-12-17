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
        // Step 1: Agar length alag hai to anagram possible hi nahi
        if (s.size() != t.size()) return false;

        // Step 2: Frequency array banao (26 letters ke liye)
        vector<int> freq(26, 0);

        // Step 3: String 's' ke har character ke liye frequency badhao
        for (char c : s) {
            freq[c - 'a']++;  // jis letter pe ho, uska count +1
        }

        // Step 4: String 't' ke har character ke liye frequency ghatayo
        for (char c : t) {
            freq[c - 'a']--;  // jis letter pe ho, uska count -1
        }

        // Step 5: Ab check karo har letter ka count 0 hai ya nahi
        for (int count : freq) {
            if (count != 0)  // agar koi bhi count non-zero mila
                return false; // to wo anagram nahi hoga
        }

        // Step 6: Agar sabhi counts 0 ho gaye to dono anagram hain
        return true;
    }
};
