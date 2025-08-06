class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        auto& A = points[0]; // x1, y1
        auto& B = points[1]; // x2, y2
        auto& C = points[2]; // x3, y3

         if (A == B || B == C || A == C)
            return false;

         // Area = 0.5 * | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) |
        int x1 = A[0], y1 = A[1];
        int x2 = B[0], y2 = B[1];
        int x3 = C[0], y3 = C[1];

        int twice_area = x1 * (y2 - y3) + 
                         x2 * (y3 - y1) + 
                         x3 * (y1 - y2);

        return twice_area != 0; // area ≠ 0 ⇒ not collinear ⇒ boomerang
    }
};
