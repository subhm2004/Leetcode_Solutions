class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> lattice_points;

        for (auto& circle : circles) {
            int x = circle[0], y = circle[1], r = circle[2];

            for (int i = x - r; i <= x + r; i++) {
                for (int j = y - r; j <= y + r; j++) {
                    // Check if point (i, j) lies inside or on the circle
                    if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r) {
                        lattice_points.insert({i, j});
                    }
                }
            }
        }

        return lattice_points.size();
    }
};