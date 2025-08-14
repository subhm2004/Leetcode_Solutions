class Solution {
public:
    void bfs(int sr, int sc, int old_color, int new_color,
             vector<vector<int>>& image) {
        int rows = image.size();
        int cols = image[0].size();

        // Direction array using pairs for (dx, dy)
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // Queue for BFS
        queue<pair<int, int>> q;
        q.push({sr, sc});

        // Change the starting cell to the new color
        image[sr][sc] = new_color;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Traverse in all 4 directions
            for (const auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // Check boundaries and conditions for BFS
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                    image[newX][newY] == old_color) {
                    // Change the color and add the cell to the queue
                    q.push({newX, newY});
                    image[newX][newY] = new_color;
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int old_color = image[sr][sc];
        if (old_color == color)
            return image; // If the new color is the same as the old color, no change is needed

        bfs(sr, sc, old_color, color, image);

        return image;
    }
};
