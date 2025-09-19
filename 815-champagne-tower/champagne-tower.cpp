class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> arr(101, vector<double>(101, 0.0));

        arr[0][0] = poured;

        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (arr[i][j] > 1.0) {
                    double over_flow = arr[i][j] - 1.0;
                    arr[i][j] = 1.0;
                    arr[i + 1][j] += over_flow / 2.0;
                    arr[i + 1][j + 1] += over_flow / 2.0;
                }
            }
        }
        return min(1.0, arr[query_row][query_glass]);
    }
};