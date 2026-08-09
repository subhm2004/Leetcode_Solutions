class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());

        double ans = 0;

        for (int i = 0; i < prices.size(); i++) {

            if (i < discounts.size())
                ans += (double)prices[i] * (100 - discounts[i]) / 100.0;
            else
                ans += prices[i];
        }

        return ans;
    }
};