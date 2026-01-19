class Solution {
public:
    int m, n, threshold;
    vector<vector<int>> prefix;

    bool is_possible(int length) {
        for (int i = length; i <= m; i++) {
            for (int j = length; j <= n; j++) {
                int sum = prefix[i][j]
                        - prefix[i - length][j]
                        - prefix[i][j - length]
                        + prefix[i - length][j - length];

                if (sum <= threshold)
                    return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& arr, int _threshold) {

        threshold = _threshold;
        m = arr.size();
        n = arr[0].size();

        prefix.assign(m + 1, vector<int>(n + 1, 0));

        // build  sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = arr[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        int low = 0;
        int high = min(m, n);
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (is_possible(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
