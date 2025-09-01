class Solution {
public:
    int solve(string& s, char target, int k) {
        int left = 0;
        int max_len = 0;
        int changes = 0;

        for (int right = 0; right < s.length(); right++) {
            if (s[right] != target)
                changes++;

            while (changes > k) {
                if (s[left] != target)
                    changes--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
    int maxConsecutiveAnswers(string s, int k) {
        int maxi_T = solve(s, 'T', k);
        int maxi_F = solve(s, 'F', k);
        return max(maxi_T, maxi_F);
    }
};