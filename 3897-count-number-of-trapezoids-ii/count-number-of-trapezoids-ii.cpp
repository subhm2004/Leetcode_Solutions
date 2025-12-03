class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        // slope -> {intercepts}
        unordered_map<float, vector<float>> slope_intercepts;

        unordered_map<int, vector<float>> midpoint_map;

        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                float slope, intercept;

                if (x2 == x1) { // vertical line
                    slope = 1e9 + 7;    
                    intercept = x1;
                } else {
                    slope = (float)(y2 - y1) / (x2 - x1);
                    intercept = (float)(y1 * dx - x1 * dy) / dx;
                }

                int midpoint_key = (x1 + x2) * 10000 + (y1 + y2);

                slope_intercepts[slope].push_back(intercept);
                midpoint_map[midpoint_key].push_back(slope);
            }
        }

        for (auto& it : slope_intercepts) {
            if (it.second.size() <= 1)
                continue;

            map<float, int> intercept_freq;

            for (float intercept : it.second) {
                intercept_freq[intercept]++;
            }

            int prev_horizontal_lines = 0;

            for (auto& entry : intercept_freq) {
                int count = entry.second;
                result += count * prev_horizontal_lines;
                prev_horizontal_lines += count;
            }
        }

        for (auto& it : midpoint_map) {
            if (it.second.size() <= 1)
                continue;

            map<float, int> slope_freq;

            for (float slope : it.second) {
                slope_freq[slope]++;
            }

            int prev_horizontal_lines = 0;

            for (auto& entry : slope_freq) {
                int count = entry.second;
                result -= count * prev_horizontal_lines;
                prev_horizontal_lines += count;
            }
        }

        return result;
    }
};
