class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2 * n) + to_string(3 * n);

        if (s.size() != 9)
            return false;

        vector<int> freq(10, 0);

        for (char c : s) {
            int d = c - '0';
            freq[d]++;
        }

        // No zeros allowed
        if (freq[0] > 0)
            return false;

        // har digit 1 to 9 bas ek baar aana chahiye
        for (int d = 1; d <= 9; d++) {
            if (freq[d] != 1)
                return false;
        }

        return true;
    }
};