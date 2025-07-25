class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max_length = 0;
        int count = 0;

        for (auto& rect : rectangles) {
            int side = min(rect[0], rect[1]);

            if (side > max_length) {
                max_length = side;
                count = 1;
            } else if (side == max_length) {
                count++;
            }
        }

        return count;
    }
};