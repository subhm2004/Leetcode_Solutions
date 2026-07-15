class Solution {
public:
    
    // Ye function count karega ki given center (cx, cy) wale circle ke andar kitne points aa rahe hain.
    int count_points_in_circle(vector<vector<int>>& darts, double cx, double cy, int r) {

        int count = 0;

        for (auto &point : darts) {

            double dx = point[0] - cx;
            double dy = point[1] - cy;

            // Agar distance <= r hai to point circle ke andar hai
            if (dx * dx + dy * dy <= 1.0 * r * r + 1e-7)
                count++;
        }

        return count;
    }

    int numPoints(vector<vector<int>>& darts, int r) {

        int n = darts.size();

        if (n == 1)
            return 1;

        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                double x1 = darts[i][0];
                double y1 = darts[i][1];

                double x2 = darts[j][0];
                double y2 = darts[j][1];

                double dx = x2 - x1;
                double dy = y2 - y1;

                // Dono points ke beech ki distance
                double d = sqrt(dx * dx + dy * dy);

                // Agar distance 2r se badi hai to radius r ka koi circle dono points se pass nahi karega
                if (d > 2.0 * r )
                    continue;

                // Midpoint
                double mx = (x1 + x2) / 2.0;
                double my = (y1 + y2) / 2.0;

                // Midpoint se center tak ki distance
                double h = sqrt(1.0 * r * r - (d / 2.0) * (d / 2.0));

                // Perpendicular unit vector
                double ux = -dy / d;
                double uy = dx / d;

                // First possible center
                double cx1 = mx + h * ux;
                double cy1 = my + h * uy;

                // Second possible center
                double cx2 = mx - h * ux;
                double cy2 = my - h * uy;

                ans = max(ans, count_points_in_circle(darts, cx1, cy1, r));
                ans = max(ans, count_points_in_circle(darts, cx2, cy2, r));
            }
        }

        return ans;
    }
};


/*
    1e-7 is a small tolerance value used to handle floating-point precision errors.

    Theoretically, a point lying exactly on the circle boundary should satisfy:
        distance² = r²

    But due to decimal precision in double calculations, it may become:
        distance² = r² + 0.0000000001

    Without tolerance, such a boundary point would be considered outside the circle.

    So we compare:
        distance² <= r² + 1e-7

    This safely includes boundary points affected only by tiny floating-point errors.
*/