// class Solution {
// public:
//     int buyChoco(vector<int>& prices, int money) {
//         sort(prices.begin(), prices.end());
//         int sum = prices[0] + prices[1];
//         if (sum <= money) {
//             return money - sum;
//         }
//         return money;
//     }
// };
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int price : prices) {
            if (price < min1) {
                min2 = min1;
                min1 = price;
            } else if (price < min2) {
                min2 = price;
            }
        }
        
        int sum = min1 + min2;
        if (sum <= money) {
            return money - sum;
        }
        return money;
    }
};
