class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        // Step 1: Frequency count
        for (char ch : s) {
            freq[ch]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (auto& [ch, count] : freq) {
            if (count % 2 == 0) {
                length += count;          // even frequency -> fully useable
            } else {
                length += count - 1;      // odd frequency -> use max even part
                hasOdd = true;            // ek character ko center me use kar sakte ho
            }
        }

        // Agar koi odd frequency tha, to center me 1 character use ho sakta hai
        if (hasOdd) {
            length += 1;
        }

        return length;
    }
};
