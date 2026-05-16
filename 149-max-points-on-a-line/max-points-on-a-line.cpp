class Solution {
public:

    int maxPoints(vector<vector<int>>& points) {

        int n = points.size();

        if(n <= 2) {
            return n;
        }

        int ans = 2;

        for(int i = 0; i < n; i++) {

            map<pair<int,int>, int> slope_count_map;

            for(int j = i + 1; j < n; j++) {

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(dx, dy);

                dx /= g;
                dy /= g;

                if(dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                if(dx == 0) {
                    dy = 1;
                }

                if(dy == 0) {
                    dx = 1;
                }

                slope_count_map[{dy, dx}]++;

                ans = max(ans, 1 + slope_count_map[{dy, dx}]);
            }
        }

        return ans;
    }
};