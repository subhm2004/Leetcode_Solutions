class Solution {
public:
    void sort_diagonal(vector<vector<int>>& mat, int row, int col) {
        int m = mat.size(), n = mat[0].size();
        vector<int> diagonal;

        // Diagonal elements ko ek vector me daalna
        int r = row, c = col;
        while (r < m && c < n) {
            diagonal.push_back(mat[r++][c++]);
        }

        // Diagonal ko sort karna
        sort(diagonal.begin(), diagonal.end());

        // Sorted values wapas matrix me daalna
        r = row, c = col;
        int i = 0;
        while (r < m && c < n) {
            mat[r++][c++] = diagonal[i++];
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        // First column ke diagonals ko process karenge
        for (int i = 0; i < m; i++) {
            sort_diagonal(mat, i, 0);
        }

        // First row ke diagonals ko process karenge (except [0,0] jo pehle se
        // ho chuka hai)
        for (int j = 1; j < n; j++) {
            sort_diagonal(mat, 0, j);
        }
        return mat;
    }
};

// ( Using Priority Queue ye achi approach hai ise hi use krnege aage se )

// class Solution {
// public:
//     void sortDiagonal(vector<vector<int>>& mat, int row, int col) {
//         int m = mat.size(), n = mat[0].size();
//         priority_queue<int, vector<int>, greater<int>> pq; // Min-Heap

//         // Pehle diagonal elements ko collect karna hai
//         int r = row, c = col;
//         while (r < m && c < n) {
//             pq.push(mat[r++][c++]);
//         }

//         // Sorted elements ko wapas matrix me daalna hai
//         r = row, c = col;
//         while (r < m && c < n) {
//             mat[r++][c++] = pq.top();
//             pq.pop();
//         }
//     }
//     vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();

//         // Sabhi diagonals ko process karenge (leftmost column aur topmost row se start)
//         for (int row = m - 1; row >= 0; row--) {
//             sortDiagonal(mat, row, 0);
//         }
//         for (int col = 1; col < n; col++) {
//             sortDiagonal(mat, 0, col);
//         }

//         return mat;
//     }


// };

