// Floating Point Binary Search
class Solution {
public:
    // Helper function: given a line at y = mid, calculates area above and below
    bool upper_area_bada_hai(double yLine, const vector<vector<int>>& arr) {
        double upper_area = 0.0;
        double lower_area = 0.0;

        for (const auto& a : arr) {
            double yBottom = a[1];
            double side = a[2];
            double yTop = yBottom + side;

            if (yBottom >= yLine) {
                // Entire a is above the line
                upper_area += side * side;
            } else if (yTop <= yLine) {
                // Entire a is below the line
                lower_area += side * side;
            } else {
                // a intersects the line
                upper_area += (yTop - yLine) * side;
                lower_area += (yLine - yBottom) * side;
            }
        }

        return upper_area > lower_area;
    }

    double separateSquares(vector<vector<int>>& arr) {
        // standard form hai binary search on floating-point values.
        double low = INT_MAX;
        double high = 0.0;
        for (const auto& sq : arr) {
            low = min(low, (double)sq[1]);           // yBottom
            high = max(high, (double)sq[1] + sq[2]); // yTop
        }

        double eps = 1e-5;

        while (high - low > eps) {
            double mid = (low + high) / 2.0;

            if (upper_area_bada_hai(mid, arr) == true) {
                low = mid; // upar cut lagega
            } else {
                high = mid; // neeche cut lagega
            }
        }

        return low;
    }
};