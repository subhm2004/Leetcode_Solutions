class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<vector<int>> squares;  // stores {left, right, height}
        vector<int> ans;
        int max_Height = 0;

        for (auto& pos : positions) {
            int left = pos[0];
            int size = pos[1];
            int right = left + size;
            int height = size;

            // Check overlap with all previous squares
            for (auto& sq : squares) {
                int prevLeft = sq[0], prevRight = sq[1], prevHeight = sq[2];
                if (left < prevRight && right > prevLeft) {
                    height = max(height, prevHeight + size);
                }
            }

            squares.push_back({left, right, height});
            max_Height = max(max_Height, height);
            ans.push_back(max_Height);
        }

        return ans;
    }
};
