class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> freq(3, 0); // 'a', 'b', 'c' ka count store karne ke liye
        int left = 0; // Window ka left boundary

        for (int right = 0; right < s.length(); ++right) {
            ++freq[s[right] - 'a']; // Current character ka count badhao

            // Jab tak 'a', 'b', 'c' sab ek baar aa chuke hain, window ko shrink karo
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                --freq[s[left] - 'a']; // Leftmost character ko hatao
                ++left; // Window ka left boundary badhao
            }

            // Har valid window se jitne substrings ban sakte hain, unka count add karo
            ans += left;
        }

        return ans;
    }
};
