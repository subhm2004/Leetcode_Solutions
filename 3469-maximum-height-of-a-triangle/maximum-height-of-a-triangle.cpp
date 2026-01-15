class Solution {
public:
    int helper(int first, int second) {
        int row = 1;
        int height = 0;
        while (true) {
            if (row & 1) { // odd row -> use first
                if (first < row)
                    break;
                first -= row;
            } else { // even row -> use second
                if (second < row)
                    break;
                second -= row;
            }
            height++;
            row++;
        }
        return height;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red, blue), helper(blue, red));
    }
};
