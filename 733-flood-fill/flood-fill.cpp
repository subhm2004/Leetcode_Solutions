class Solution {
public:
    vector<vector<int>> image;

    void bfs(int sr, int sc, int old_color, int new_color) {
        int rows = image.size();
        int cols = image[0].size();

        vector<pair<int, int>> direction = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = new_color;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto &[dx, dy] : direction) {
                int new_row = row + dx;
                int new_col = col + dy;

                if (new_row >= 0 && new_row < rows &&
                    new_col >= 0 && new_col < cols &&
                    image[new_row][new_col] == old_color) {

                    image[new_row][new_col] = new_color;
                    q.push({new_row, new_col});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        this->image = img;

        int old_color = image[sr][sc];

        if (old_color == color) {
            return image;
        }

        bfs(sr, sc, old_color, color);

        return image;
    }
};