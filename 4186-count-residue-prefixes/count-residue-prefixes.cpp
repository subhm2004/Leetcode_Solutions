class Solution {
public:
    int residuePrefixes(string s) {
        vector<bool> seen(26, false);
        int distinct_count = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            if (!seen[ch]) {
                seen[ch] = true;
                distinct_count++;
            }

            int prefix_len = i + 1; // 1-based length
            if (distinct_count == prefix_len % 3)
                ans++;
        }
        return ans;
    }
};