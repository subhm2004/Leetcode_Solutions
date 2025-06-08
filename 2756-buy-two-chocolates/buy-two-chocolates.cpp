class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min_sum = INT_MAX;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = prices[i] + prices[j];
                if (sum <= money && sum < min_sum) {
                    min_sum = sum;
                }
            }
        }
        if (min_sum == INT_MAX)
            return money;
        return money - min_sum;
    }
};
