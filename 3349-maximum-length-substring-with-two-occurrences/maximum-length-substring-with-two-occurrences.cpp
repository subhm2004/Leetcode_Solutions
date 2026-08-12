// Same as LC 2958
class Solution {
public:
    int solve(string& str, int k) {

        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < str.size(); right++) {

            // Current element ko window mein add karo
            freq[str[right]]++;

            // Agar koi element k se zyada baar aa gaya,
            // toh window invalid ho gayi
            while (freq[str[right]] > k) {

                // Left se elements remove karte jao
                freq[str[left]]--;
                left++;
            }

            // Ab current window good hai
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
    int maximumLengthSubstring(string s) { return solve(s, 2); }
};