class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        // Step 1: Frequency count
        for (char ch : s) {
            freq[ch]++;
        }

        int length = 0;
        bool has_odd = false;

        for (auto& [ch, count] : freq) {
            if (count % 2 == 0) {
                length += count;          // even frequency -> fully useable
            } else {
                length += count - 1;      // odd frequency -> use max even part
                has_odd = true;            // ek character ko center me use kar sakte ho
            }
        }

        // Agar koi odd frequency tha, to center me 1 character use ho sakta hai
        if (has_odd) {
            length += 1;
        }

        return length;
    }
};
