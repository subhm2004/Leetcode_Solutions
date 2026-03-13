// minimize the maximum pattern
class Solution {
public:
using ll = long long;
    int mountain_height;
    vector<int> arr;

    bool is_possible(ll mid_height) {
        ll curr_height = 0;
        for (int wt : arr) {
            ll x = ((-1 + sqrt(1 + 8.0 * mid_height / wt)) / 2);
            curr_height += x;
            if (curr_height >= mountain_height) {
                return true;
            }
        }
        return false;
    }

    ll minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        mountain_height = mountainHeight;
        arr = workerTimes;

        ll low = 0;
        ll high = LLONG_MAX;
        ll ans = INT_MAX;

        while (low <= high) {
            ll mid = (low + high) >> 1;
            if (is_possible(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};