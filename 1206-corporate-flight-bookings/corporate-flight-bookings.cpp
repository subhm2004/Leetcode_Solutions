class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);   

        for (auto& booking : bookings) {
            int l = booking[0] - 1;  // 0-based me convet kar diya  
            int r = booking[1] - 1;  // 0-based me convet kar diya 
            int seats = booking[2];

            diff[l] += seats;
            if (r + 1 < n)
                diff[r + 1] -= seats;
        }

        // Prefix sum nikalo
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }
};
