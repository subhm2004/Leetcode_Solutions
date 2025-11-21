class Solution {    // badhiya method hai 
public:
// expand around center
    int count_palindrom(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            //  odd-length palindromes
            count += count_palindrom(s, i, i);

            //  even-length palindromes
            count += count_palindrom(s, i, i + 1);
        }

        return count;
    }
};



//-----------------------------------------------------------------------------------------------------

