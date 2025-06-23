// class Solution {   // MLE
// public:
//     int maxCount(int m, int n, vector<vector<int>>& ops) {
//         vector<vector<int>> matrix(m, vector<int>(n, 0));

//         for (auto& op : ops) {
//             int a = op[0];
//             int b = op[1];

//             for (int i = 0; i < a; ++i) {
//                 for (int j = 0; j < b; ++j) {
//                     matrix[i][j]++;
//                 }
//             }
//         }

//         // Find max_valuemum value in the matrix
//         int max_value = 0;
//         for (int i = 0; i < m; ++i)
//             for (int j = 0; j < n; ++j)
//                 max_value = max(max_value, matrix[i][j]);

//         // Count how many cells have the maximum value
//         int count = 0;
//         for (int i = 0; i < m; ++i)
//             for (int j = 0; j < n; ++j)
//                 if (matrix[i][j] == max_value)
//                     count++;

//         return count;
//     }
// };
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_Row = m;
        int min_Col = n;

        for (auto& op : ops) {
            min_Row = min(min_Row, op[0]);  // smallest ai
            min_Col = min(min_Col, op[1]);  // smallest bi
        }

        return min_Row * min_Col;
    }
};
