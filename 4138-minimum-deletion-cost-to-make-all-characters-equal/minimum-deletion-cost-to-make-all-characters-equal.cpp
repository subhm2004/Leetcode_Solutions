class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long total = 0;
        for (int c : cost) total += c;   // sab delete karne ka total cost

        vector<long long> sum(26, 0);

        // har character ka total cost jod do
        for (int i = 0; i < s.size(); i++) {
            sum[s[i] - 'a'] += cost[i];
        }

        long long ans = LLONG_MAX;

        // ek character chhod kar baaki sab delete
        for (int i = 0; i < 26; i++) {
            if (sum[i] > 0) {
                ans = min(ans, total - sum[i]);
            }
        }

        return ans;
    }
};