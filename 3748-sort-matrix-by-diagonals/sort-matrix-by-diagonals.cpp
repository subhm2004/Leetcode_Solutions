// class Solution {
// public:
//     void sortDiagonal(vector<vector<int>>& grid, int row, int col, bool descending) {
//         int n = grid.size();
//         vector<int> diagonal;

//         int r = row, c = col;
//         while (r < n && c < n) {
//             diagonal.push_back(grid[r++][c++]);
//         }

//         if (descending)
//             sort(diagonal.begin(), diagonal.end(), greater<int>());
//         else
//             sort(diagonal.begin(), diagonal.end());

//         for (int i = 0, r = row, c = col; i < diagonal.size(); i++, r++, c++) {
//             grid[r][c] = diagonal[i];
//         }
//     }

//     vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();

//         for (int i = 0; i < n; i++)
//             sortDiagonal(grid, i, 0, true);

//         for (int j = 1; j < n; j++)
//             sortDiagonal(grid, 0, j, false);

//         return grid;
//     }
// };

class Solution {
public:
    void sortDiagonal(vector<vector<int>>& grid, int row, int col,
                      bool descending) {
        int n = grid.size();

        // Priority Queue (Heap) - Min-Heap ya Max-Heap
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Diagonal elements heap me daal rahe hain
        int r = row, c = col;
        while (r < n && c < n) {
            if (descending)
                maxHeap.push(grid[r][c]); // Max-Heap for descending order
            else
                minHeap.push(grid[r][c]); // Min-Heap for ascending order
            r++, c++;
        }

        // Heap se sorted elements wapas grid me daal rahe hain
        r = row, c = col;
        while (r < n && c < n) {
            if (descending) {
                grid[r][c] = maxHeap.top();
                maxHeap.pop();
            } else {
                grid[r][c] = minHeap.top();
                minHeap.pop();
            }
            r++, c++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Leftmost column se diagonals sort kar rahe hain (Descending order)
        for (int i = 0; i < n; i++)
            sortDiagonal(grid, i, 0, true);

        // Topmost row se diagonals sort kar rahe hain (Ascending order)
        for (int j = 1; j < n; j++)
            sortDiagonal(grid, 0, j, false);

        return grid;
    }
};
