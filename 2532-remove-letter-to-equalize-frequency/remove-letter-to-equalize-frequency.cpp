class Solution {
public:

    // Helper function: check karega kya non-zero freq values same hain
    bool allSame(const vector<int>& freq) {
        int same = -1;

        for (auto& f : freq) {
            if (f == 0) continue;
            if (same == -1) same = f;  // Pehli baar freq mila to usse set karo
            else if (f != same) return false;  // Agar alag mila to false
        }

        return true;
    }

    bool equalFrequency(string word) {
        vector<int> freq(26, 0);

        // Har character ka frequency count karo
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Har character ko ek baar remove karke check karo kya baki sabka freq same hai
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) continue;

            freq[i]--;  // Ek character hatao

            if (allSame(freq))  // Check karo sabka freq same hai kya
                return true;

            freq[i]++;  // Wapas original freq pe lao
        }

        return false;  // Koi bhi aisa case nahi mila
    }
};
