class Solution {
public:
    bool is_balanced(vector<int>& freq) {
        int mini = INT_MAX, maxi = 0;
        for (int f : freq) {
            if (f > 0) {
                mini = min(mini, f);
                maxi = max(maxi, f);
            }
        }
        return mini == maxi;
    }
    
    int longestBalanced(string s) {
        int n = s.size();
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if (is_balanced(freq)) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};