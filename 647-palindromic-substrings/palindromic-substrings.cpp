// class Solution {    // badhiya method hai 
// public:
//     int count_palindrom(string s, int left, int right) {
//         int count = 0;
//         while (left >= 0 && right < s.size() && s[left] == s[right]) {
//             count++;
//             left--;
//             right++;
//         }
//         return count;
//     }

//     int countSubstrings(string s) {
//         int count = 0;
//         int n = s.size();
//         for (int i = 0; i < n; i++) {
//             //  odd-length palindromes
//             count += count_palindrom(s, i, i);

//             //  even-length palindromes
//             count += count_palindrom(s, i, i + 1);
//         }

//         return count;
//     }
// };



//-----------------------------------------------------------------------------------------------------


class Solution {
public:
    int solve_bottom_up(string &s) {
        int n = s.length();
        int count = 0;

        // dp[i][j] = true agar s[i..j] ek palindrome hai
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // L = length of substring
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;

                if (L == 1) {
                    dp[i][j] = true;
                } else if (L == 2) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }

                if (dp[i][j]) count++;
            }
        }

        return count;
    }

    int countSubstrings(string s) {
        return solve_bottom_up(s);
    }
};
