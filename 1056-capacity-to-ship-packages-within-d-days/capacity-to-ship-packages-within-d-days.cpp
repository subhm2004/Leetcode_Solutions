class Solution {
public:
    bool is_possible(vector<int>& weights, int days, int capacity) {

        int days_required = 1;
        int curr_load = 0;

        for (int weight : weights) {

            if (curr_load + weight > capacity) {
                days_required++;
                curr_load = 0;
            }

            curr_load += weight;
        }

        return days_required <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = INT_MAX;
        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (is_possible(weights, days, mid)) {
                ans = mid;
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};