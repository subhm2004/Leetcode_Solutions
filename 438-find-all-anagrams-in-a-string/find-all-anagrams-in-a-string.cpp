// auto __fast_io_atexit = []() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     std::atexit([]() { 
//         ofstream("display_runtime.txt") << "0"; 
//     });

//     return 0;
// }();
// class Solution {
// public:
//     bool is_anagram_freq(vector<int>& a, vector<int>& b) {
//         for (int i = 0; i < 26; i++)
//             if (a[i] != b[i]) return false;
//         return true;
//     }

//     vector<int> findAnagrams(string s, string p) {
//         int n = s.size(), m = p.size();
//         vector<int> ans;
//         if (n < m) return ans;

//         vector<int> p_freq(26, 0), window_freq(26, 0);

//         // Count frequency for p
//         for (char c : p) p_freq[c - 'a']++;

//         // Sliding window
//         for (int i = 0; i < n; i++) {
//             window_freq[s[i] - 'a']++; // add current character to window

//             if (i >= m) 
//                 window_freq[s[i - m] - 'a']--; // remove character going out of window

            
            
//             // Check for anagram only when the window size is at least m
//             if (i >= m - 1 && is_anagram_freq(window_freq, p_freq))
//                 ans.push_back(i - m + 1); // store starting index
//         }

//         return ans;
//     }
// };
// // safety check k liye hum add kr skte the ki i>= m-1 tak index out of boun na jaye 



// ye standard way se code kiya hai left of right pointer ka use krke 
class Solution {
public:
    // Function to check if two frequency arrays match
    bool is_anagram_freq(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i]) return false;
        return true;
    }

    vector<int> findAnagrams(string s, string t) {
        vector<int> ans;
        int n = s.size(), m = t.size();
        if (n < m) return ans;

        vector<int> t_freq(26, 0);     // frequency of characters in t
        vector<int> window(26, 0);     // frequency of characters in current window

        for (char c : t) t_freq[c - 'a']++;

        int left = 0;

        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++; // add current char to window

            // Shrink window if size > m
            if (right - left + 1 > m) {
                window[s[left] - 'a']--; // remove leftmost char
                left++;
            }

            // Check for anagram only when window size == m
            if (right - left + 1 == m && is_anagram_freq(window, t_freq)) {
                ans.push_back(left); // store starting index
            }
        }

        return ans;
    }
};