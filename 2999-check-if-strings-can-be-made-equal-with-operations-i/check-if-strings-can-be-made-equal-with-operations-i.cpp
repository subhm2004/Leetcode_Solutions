class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        int freq_even[26] = {0};
        int freq_odd[26] = {0};

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                freq_even[s1[i] - 'a']++;
                freq_even[s2[i] - 'a']--;
            } else {
                freq_odd[s1[i] - 'a']++;
                freq_odd[s2[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq_odd[i] != 0 || freq_even[i] != 0)
                return false;
        }
        return true;
    }
};