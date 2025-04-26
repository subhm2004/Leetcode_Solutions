class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        map<char, int> mp;  // 't' ke characters ka frequency map bana rahe hain
        
        for (char &ch : t) {
            mp[ch]++;  // har character ke count ko badha rahe hain
        }
        
        int requiredCount = t.length();  // total kitne characters chahiye (including duplicates)
        int i = 0, j = 0;
        int minStart = 0;  // minimum window ka starting index
        int minWindow = INT_MAX;  // minimum window ka size initially infinity set kar diya

        while (j < n) {
            char ch_j = s[j];
            if (mp[ch_j] > 0)
                requiredCount--;  // jab ek required character milta hai, count kam karte hain
            
            mp[ch_j]--;  // current character ko map me decrease karte hain (even if not required)

            // Jab saare required characters mil jaayein toh window ko shrink karne ki koshish karo
            while (requiredCount == 0) {
                if (minWindow > j - i + 1) {
                    minWindow = j - i + 1;  // naya minimum window update karo
                    minStart = i;  // naya starting index update karo
                }
                
                char ch_i = s[i];
                mp[ch_i]++;  // window se ek character hata rahe hain, isliye uska count badha rahe hain
                if (mp[ch_i] > 0)
                    requiredCount++;  // agar hataya hua character required tha, toh requiredCount badhao
                i++;  // left pointer ko aage badhao
            }
            
            j++;  // right pointer ko aage badhao (ye mat bhoolna \U0001f604)
        }
        
        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);  // agar koi window nahi mila toh empty string
    }
};
