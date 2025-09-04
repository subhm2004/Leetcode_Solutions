// class Solution {
// public:
//     int maximumGroups(vector<int>& grades) {
//         int n = grades.size();
//         int k = (-1 + sqrt(1 + 8 * n)) / 2;
//         return k;
//     }
// };

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int low = 1;
        int high = n;
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) >> 1;
            long long sum = 1LL * mid * (mid + 1) / 2;

            if (sum <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};