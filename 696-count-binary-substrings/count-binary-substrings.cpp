class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prevCount = 0, currCount = 1;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++currCount;  // Continue counting consecutive same characters
            } else {
                ans += min(prevCount, currCount);  // Add the minimum of previous and current counts
                prevCount = currCount;  // Update previous count
                currCount = 1;  // Reset current count for the new character
            }
        }

        // Final check for the last group of characters
        ans += min(prevCount, currCount);

        return ans;
    }
};
