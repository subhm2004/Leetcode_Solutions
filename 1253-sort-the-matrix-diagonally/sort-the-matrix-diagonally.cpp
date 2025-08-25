class Solution {
public:
    void sort_diagonal(vector<vector<int>>& arr, int row, int col) {
        int m = arr.size(), n = arr[0].size();
        vector<int> diagonal;

        // Diagonal elements ko ek vector me daalna
        int r = row, c = col;
        while (r < m && c < n) {
            diagonal.push_back(arr[r++][c++]);
        }

        // Diagonal ko sort karna
        sort(diagonal.begin(), diagonal.end());

        // Sorted values wapas arrrix me daalna
        r = row, c = col;
        int i = 0;
        while (r < m && c < n) {
            arr[r++][c++] = diagonal[i++];
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        // First column ke diagonals ko process karenge
        for (int i = 0; i < m; i++) {
            sort_diagonal(arr, i, 0);
        }

        // First row ke diagonals ko process karenge (except [0,0] jo pehle se ho chuka hai)
        for (int j = 1; j < n; j++) {
            sort_diagonal(arr, 0, j);
        }
        return arr;
    }
};

 