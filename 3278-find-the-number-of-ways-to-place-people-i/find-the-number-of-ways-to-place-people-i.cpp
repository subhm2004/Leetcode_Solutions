// class Solution {
// public:
//     int numberOfPairs(vector<vector<int>>& points) {
//         int n = points.size();

//         int ans = 0;

//         // check every pair (A,B)
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == j)
//                     continue;

//                 int Ax = points[i][0], Ay = points[i][1];
//                 int Bx = points[j][0], By = points[j][1];

//                 // condition: A is upper-left of B (including same coordinates)
//                 if (Ax <= Bx && Ay >= By) {
//                     bool valid = true;

//                     // check if any other point lies inside rectangle (or on border)
//                     for (int k = 0; k < n; k++) {
//                         if (k == i || k == j)
//                             continue;
//                         int Cx = points[k][0], Cy = points[k][1];
//                         if (Ax <= Cx && Cx <= Bx && By <= Cy && Cy <= Ay) {
//                             valid = false;
//                             break;
//                         }
//                     }

//                     if (valid){
//                         ans++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };




//-------------------------------------

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        // Sort: x ascending, if x same then sort as y descending
        auto lambda = [](vector<int>& point1, vector<int>& point2) {
            if (point1[0] == point2[0]) {
                return point1[1] > point2[1];
            }
            return point1[0] < point2[0];
        };

        sort(points.begin(), points.end(), lambda);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];   // upper left

            int max_Y = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];   // lower right

                // Condition: (x2, y2) must be above (x1, y1)
                if (y2 > y1) { //not lower right
                    continue;
                }

                if (y2 > max_Y) {
                    ans++;
                    max_Y = y2;
                }
            }
        }

        return ans;
    }
};
