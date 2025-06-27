class Solution {
public:
    // Helper function: given a line at y = mid, calculates area above and below
    bool upper_area_bada_hai(double yLine, const vector<vector<int>>& arr) {
        double upperArea = 0.0, lowerArea = 0.0;

        for (const auto& a : arr) {
            double yBottom = a[1];
            double side = a[2];
            double yTop = yBottom + side;

            if (yBottom >= yLine) {
                // Entire a is above the line
                upperArea += side * side;
            } else if (yTop <= yLine) {
                // Entire a is below the line
                lowerArea += side * side;
            } else {
                // a intersects the line
                upperArea += (yTop - yLine) * side;
                lowerArea += (yLine - yBottom) * side;
            }
        }

        return upperArea > lowerArea;
    }

     double separateSquares(vector<vector<int>>& arr) {
        double low = 0.0;
        double high = 1e9 + 7.0;
        double eps = 1e-6;
        double ans = 0.0;

        while (low <= high) {
            double mid = (low + high) / 2.0;

            if (upper_area_bada_hai(mid, arr)) {
                ans = mid;      
                low = mid + eps;
            } else {
                high = mid - eps;
            }
        }

        return ans;
    }
};
