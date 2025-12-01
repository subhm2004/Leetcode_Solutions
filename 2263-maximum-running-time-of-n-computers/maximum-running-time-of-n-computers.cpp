class Solution {
public:
    bool is_possible(long long T, int n, const vector<int>& batteries) {
        long long usable = 0;
        for (long long b : batteries) {
            usable += min(b, T);
        }
        return usable >= T * n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (long long b : batteries) total += b;

        long long left = 1, right = total / n, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (is_possible(mid, n, batteries)) {
                ans = mid;
                left = mid + 1;    
            } else {
                right = mid - 1;   
            }
        }

        return ans;
    }
};
