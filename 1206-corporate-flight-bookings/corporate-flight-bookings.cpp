class Solution {
public:
    vector<int> difference_array_technique(vector<vector<int>>& queries, int n) {
        vector<int> diff(n, 0);

        // Step 1: Use for-each loop to apply each query
        for (const auto& q : queries) {
            int l = q[0] - 1;
            int r = q[1] - 1;
            int val = q[2];

            diff[l] += val;
            if (r + 1 < n)
                diff[r + 1] -= val;
        }

        // Step 2: Prefix sum to apply the difference array
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        return difference_array_technique(bookings, n);
    }
};
