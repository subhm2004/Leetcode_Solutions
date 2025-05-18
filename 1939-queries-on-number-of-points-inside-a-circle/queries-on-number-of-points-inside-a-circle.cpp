class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto& query : queries) {
            int x = query[0];
            int y = query[1];
            int r = query[2];
            int count = 0;

            for (auto& point : points) {
                int px = point[0];
                int py = point[1];

                int dx = px - x;
                int dy = py - y;
                if (dx*dx + dy*dy <= r*r) {
                    count++;
                }
            }
            ans.push_back(count);
        }

        return ans;
    }
};
