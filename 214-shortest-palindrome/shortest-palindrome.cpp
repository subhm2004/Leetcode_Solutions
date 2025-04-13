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

class Solution {          // KMP algo
public:
    string shortestPalindrome(string s) {
        int n = s.size();

        // Step 1: Reverse the original string
        string reversed = s;
        reverse(reversed.begin(), reversed.end());

        // Step 2: Create a combined string to apply KMP
        string combined = s + "#" + reversed;

        // Step 3: Build the LPS (Longest Prefix Suffix) array
        int m = combined.size();
        vector<int> lps(m, 0);

        for (int i = 1; i < m; ++i) {
            int len = lps[i - 1];

            // Backtrack until match is found or len becomes 0
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }

            // If characters match, increment length
            if (combined[i] == combined[len]) {
                ++len;
            }

            lps[i] = len;
        }

        // Step 4: LPS tells us the longest palindrome starting at index 0
        int palinPrefixLen = lps[m - 1];

        // Step 5: Take remaining suffix, reverse it and add in front
        string remainingSuffix = s.substr(palinPrefixLen);
        reverse(remainingSuffix.begin(), remainingSuffix.end());

        // Final shortest palindrome
        return remainingSuffix + s;
    }
};

