class Solution {
public:
    bool is_anagram_freq(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i]) return false;
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> ans;
        if (n < m) return ans;

        vector<int> p_freq(26, 0), window_freq(26, 0);

        // Count frequency for p
        for (char c : p) p_freq[c - 'a']++;

        // Sliding window
        for (int i = 0; i < n; i++) {
            window_freq[s[i] - 'a']++; // add current character to window

            if (i >= m) 
                window_freq[s[i - m] - 'a']--; // remove character going out of window

            if (is_anagram_freq(window_freq, p_freq))
                ans.push_back(i - m + 1); // store starting index
        }

        return ans;
    }
};
