class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> pos;
        int n = s.size();
        
        // Har character ke positions store karo s me
        for (int i = 0; i < n; i++) {
            pos[s[i]].push_back(i);
        }

        int count = 0;

        for (auto &word : words) {
            int prev = -1;
            bool is_subseq = true;
            for (char ch : word) {
                if (!pos.count(ch)) {  // Agar character s me exist nahi karta
                    is_subseq = false;
                    break;
                }
                // c ka pehla index dhundo jo prev se bada ho
                auto it = upper_bound(pos[ch].begin(), pos[ch].end(), prev);
                if (it == pos[ch].end()) { // Agar koi valid position nahi mila
                    is_subseq = false;
                    break;
                }
                prev = *it; // Last matched index update karo
            }
            if (is_subseq) count++;
        }

        return count;
    }
};


// class Solution { // Brute Force TLE O(n*m)
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int count = 0;
//         for (auto &word : words) {
//             int j = 0;
//             for (int i = 0; i < s.size() && j < word.size(); i++) {
//                 if (s[i] == word[j]) j++;
//             }
//             if (j == word.size()) count++;
//         }
//         return count;
//     }
// };

// class Solution {
// public:
//     bool is_subsequence(string& s, string& word, int i, int j) {
//         // Agar s khatam ho gaya ya word ke end tak pahunch gaye
//         // To check karo ki word ka sara part match ho gaya ya nahi
//         // Agar j == word.size() → poora word match hua → true
//         // Agar j != word.size() → s khatam ho gaya aur word ka kuch match nahi hua → false
//         if(i == s.size() || j == word.size()) return j == word.size();

//         if (s[i] == word[j])
//             return is_subsequence(s, word, i + 1, j + 1);
//         else
//             return is_subsequence(s, word, i + 1, j);
//     }

//     int numMatchingSubseq(string s, vector<string>& words) {
//         int count = 0;
//         for (auto& word : words) {
//             if (is_subsequence(s, word, 0, 0))
//                 count++;
//         }
//         return count;
//     }
// };

