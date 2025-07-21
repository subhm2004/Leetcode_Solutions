class Solution {
public:
    // check krta hai ki we can pick k candies with at least mid tastiness
    bool is_Possible(vector<int>& price, int k, int mid) {
        int count = 1;
        int last = price[0];

        for (int i = 1; i < price.size(); ++i) {
            if (price[i] - last >= mid) {
                count++;
                last = price[i];
            }
        }

        return count >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int low = 0 ;
        int high = price.back() - price.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (is_Possible(price, k, mid)) {
                ans = mid;         // mid is valid, try to go higher
                low = mid + 1;
            } else {
                high = mid - 1;   // reduce tastiness
            }
        }

        return ans;
    }
};
