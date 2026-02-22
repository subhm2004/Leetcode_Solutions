class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();

        long long total_sum = 1LL * mean * (n + m);
        long long known_sum = 0;

        for (int x : rolls)
            known_sum += x;

        long long missing_sum = total_sum - known_sum;

        // possible range check
        if (missing_sum < n || missing_sum > 1LL * 6 * n)
            return {};

        vector<int> ans(n, missing_sum / n);
        int remaining_values = missing_sum % n;

        // distribute remaining value
        for (int i = 0; i < n && remaining_values > 0; i++) {
            ans[i]++;
            remaining_values--;
        }

        return ans;
    }
};