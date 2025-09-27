// Shoelace Formula
// class Solution {
// public:
//     double largestTriangleArea(vector<vector<int>>& points) {
//         double ans = 0;

//         for (int i = 0; i < points.size(); ++i) {
//             for (int j = i + 1; j < points.size(); ++j) {
//                 for (int k = j + 1; k < points.size(); ++k) {
//                     // (1/2) |x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|
//                     double area =
//                         0.5 * abs(points[i][0] * (points[j][1] - points[k][1]) +
//                                   points[j][0] * (points[k][1] - points[i][1]) +
//                                   points[k][0] * (points[i][1] - points[j][1]));
//                     ans = max(ans, area);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Herons Formula
// class Solution {
// public:
//     double largestTriangleArea(vector<vector<int>>& points) {
//         double ans = 0;

//         auto dist = [&](vector<int>& a, vector<int>& b) {
//             return sqrt((a[0] - b[0]) * 1.0 * (a[0] - b[0]) + 
//                         (a[1] - b[1]) * 1.0 * (a[1] - b[1]));
//         };

//         for (int i = 0; i < points.size(); ++i) {
//             for (int j = i + 1; j < points.size(); ++j) {
//                 for (int k = j + 1; k < points.size(); ++k) {
//                     double a = dist(points[i], points[j]);
//                     double b = dist(points[j], points[k]);
//                     double c = dist(points[k], points[i]);
//                     double s = (a + b + c) / 2.0;
//                     double area = sqrt(max(0.0, s * (s - a) * (s - b) * (s - c)));
//                     ans = max(ans, area);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Trignometric formula 
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0.0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Vectors AB and AC
                    double ABx = points[j][0] - points[i][0];
                    double ABy = points[j][1] - points[i][1];
                    double ACx = points[k][0] - points[i][0];
                    double ACy = points[k][1] - points[i][1];

                    // Lengths of AB and AC
                    double AB = sqrt(ABx * ABx + ABy * ABy);
                    double AC = sqrt(ACx * ACx + ACy * ACy);

                    if (AB == 0 || AC == 0) continue;

                    // Dot product
                    double dot = ABx * ACx + ABy * ACy;

                    // cos(theta)
                    double cosTheta = dot / (AB * AC);

                    // sin(theta)
                    double sinTheta = sqrt(max(0.0, 1 - cosTheta * cosTheta));

                    // Area = 1/2 * AB * AC * sin(theta)
                    double area = 0.5 * AB * AC * sinTheta;
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};


