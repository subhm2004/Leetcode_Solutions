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

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;

        auto dist = [&](vector<int>& a, vector<int>& b) {
            return sqrt((a[0] - b[0]) * 1.0 * (a[0] - b[0]) + 
                        (a[1] - b[1]) * 1.0 * (a[1] - b[1]));
        };

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    double a = dist(points[i], points[j]);
                    double b = dist(points[j], points[k]);
                    double c = dist(points[k], points[i]);
                    double s = (a + b + c) / 2.0;
                    double area = sqrt(max(0.0, s * (s - a) * (s - b) * (s - c)));
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
