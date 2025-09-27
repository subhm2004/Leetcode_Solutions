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
