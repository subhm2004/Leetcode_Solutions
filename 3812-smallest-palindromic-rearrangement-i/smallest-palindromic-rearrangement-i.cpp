class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int n = s.size();
        string left = "";

        // Construct left part of palindrome (up to (n+1)/2 chars)
        for (int i = 0; i < 26; ++i) {
            while (freq[i] >= 2 && left.size() < (n + 1) / 2) {
                left += (char)(i + 'a');
                freq[i] -= 2;
            }
        }

        // Add a middle character if needed (for odd-length strings)
        string middle = "";
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                middle = (char)(i + 'a');
                break;
            }
        }

        // Create the right half by reversing the left (only first n/2 characters)
        string right = left.substr(0, n / 2);
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};
