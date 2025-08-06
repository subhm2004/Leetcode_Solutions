class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        auto& A = points[0];
        auto& B = points[1];
        auto& C = points[2];

         if (A == B || B == C || A == C) return false;

         int area = (B[0] - A[0]) * (C[1] - A[1]) - 
                   (B[1] - A[1]) * (C[0] - A[0]);

        return area != 0;
    }
};
