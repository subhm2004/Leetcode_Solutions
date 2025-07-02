// class Solution {        //TLE 121/126
// public:
//     string shortestPalindrome(string s) {
//         int n = s.size();
//         int end = n;

//         // Sabse longest prefix dhundhna jo ek palindrome ho
//         while (end > 0) {
//             string prefix = s.substr(0, end);          // prefix nikaal rahe hain
//             string revPrefix = prefix;                 
//             reverse(revPrefix.begin(), revPrefix.end()); // uska reverse le rahe hain

//             if (prefix == revPrefix) break; // agar prefix palindrome hai toh break kar do
//             end--;                          // warna end ko ek kam kar ke check karo
//         }

//         // jo remaining suffix hai uska reverse leke aage add karna hai
//         string suffix = s.substr(end);         // suffix jo palindrome part ke baad bacha
//         reverse(suffix.begin(), suffix.end()); // uska reverse liya

//         return suffix + s; // reverse suffix ko original s ke aage laga diya
//     }
// };

class Solution {
public:
    void compute_LPS(string pattern, vector<int>& lps) {
        int length = 0;
        lps[0] = 0;

        for (int i = 1; i < pattern.size(); ++i) {
            while (length > 0 && pattern[i] != pattern[length]) {
                length = lps[length - 1];
            }
            if (pattern[i] == pattern[length]) {
                length++;
            }
            lps[i] = length;
        }
    }

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string combined = s + "#" + rev;

        vector<int> lps(combined.size(), 0);
        compute_LPS(combined, lps);

        int palinPrefixLen = lps.back(); // Last value of LPS array

        string suffix = s.substr(palinPrefixLen);
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }
};
