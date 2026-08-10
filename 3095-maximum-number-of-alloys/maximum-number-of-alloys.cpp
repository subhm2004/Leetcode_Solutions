class Solution {
public:
    vector<vector<int>> composition;
    vector<int> stock, cost;
    int budget;

    bool is_possible(long long alloys, int machine) {

        long long coins = 0;

        for (int i = 0; i < stock.size(); i++) {

            long long required = 1LL * composition[machine][i] * alloys;

            if (required > stock[i]) {

                coins += (required - stock[i]) * cost[i];

                if (coins > budget)
                    return false;
            }
        }

        return true;
    }

    int maxNumberOfAlloys(int n, int k, int budget,
                          vector<vector<int>>& composition, vector<int>& stock,
                          vector<int>& cost) {

        this->composition = composition;
        this->stock = stock;
        this->cost = cost;
        this->budget = budget;

        int ans = 0;

        for (int machine = 0; machine < k; machine++) {

            long long low = 0;
            long long high = 1e9;

            while (low <= high) {

                long long mid = low + (high - low) / 2;

                if (is_possible(mid, machine)) {

                    ans = max(ans, (int)mid);
                    low = mid + 1;
                } else {

                    high = mid - 1;
                }
            }
        }

        return ans;
    }
};