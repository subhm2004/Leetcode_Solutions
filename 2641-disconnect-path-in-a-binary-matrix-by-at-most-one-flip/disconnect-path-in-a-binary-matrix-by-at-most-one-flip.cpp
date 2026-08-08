class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& arr, int i, int j) {
        if (i >= m || j >= n || arr[i][j] == 0)
            return false;
        if (i == m - 1 && j == n - 1)
            return true;

        // mark as visited path uda diya gayab kr dya
        arr[i][j] = 0;

        return dfs(arr, i + 1, j) || dfs(arr, i, j + 1);
    }

    bool isPossibleToCutPath(vector<vector<int>>& arr) {
        m = arr.size();
        n = arr[0].size();

        // agar already path exist nhi karta
        if (!dfs(arr, 0, 0))
            return true;

        arr[0][0] = 1, arr[m - 1][n - 1] = 1;

        return !dfs(arr, 0, 0);
    }
};