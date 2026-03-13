class Solution {
public:
    int mountain_height;
    vector<int> arr;
    bool is_possible(long long mid) {
        long long curr = 0;
        for (int wt : arr) {
            long long x = ((-1 + sqrt(1 + 8.0 * mid / wt)) / 2);
            curr += x;
            if (curr >= mountain_height) {
                return true;
            }
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        mountain_height = mountainHeight;
        arr = workerTimes;

        long long low = 0;
        long long high = LLONG_MAX;
        long long ans = INT_MAX;

        while (low <= high) {
            long long mid = (low + high) >> 1;
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