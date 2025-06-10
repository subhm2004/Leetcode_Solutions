class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char c : s)
            freq[c]++;

        int maxOdd = INT_MIN, minEven = INT_MAX;

        // Find max odd frequency and min even frequency
        for (auto [ch, f] : freq) {
            if (f & 1)
                maxOdd = max(maxOdd, f);
            else
                minEven = min(minEven, f);
        }

        return maxOdd - minEven;
    }
};
