// class Solution {
// public:
//     int minTimeToVisitAllPoints(vector<vector<int>>& points) {
//         int steps = 0;
        
//         for (int i = 0; i < points.size() - 1; ++i) {
//             int dx = abs(points[i+1][0] - points[i][0]);
//             int dy = abs(points[i+1][1] - points[i][1]);
//             steps += min(dx, dy) + abs(dx - dy);
//         }

//         return steps;
//     }
// };


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int steps = 0;
        
        for (int i = 0; i < points.size() - 1; ++i) {
            int dx = abs(points[i+1][0] - points[i][0]);
            int dy = abs(points[i+1][1] - points[i][1]);
            steps += max(dx, dy); // Chebyshev distance
        }

        return steps;
    }
};
