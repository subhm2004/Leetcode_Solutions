class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        
        // Copy input string to modify
        string temp = s;

        int length = n - 1;  // Start with length - 1 since each step reduces the size
        while (length > 1) {
            for (int i = 0; i < length; ++i) {
                // Compute new digit by summing adjacent ones, modulo 10
                temp[i] = ((temp[i] - '0') + (temp[i + 1] - '0')) % 10 + '0';
            }
            length--;  // Reduce length in each iteration
        }

        // Check if the last two digits are the same
        return temp[0] == temp[1];
    }
};
