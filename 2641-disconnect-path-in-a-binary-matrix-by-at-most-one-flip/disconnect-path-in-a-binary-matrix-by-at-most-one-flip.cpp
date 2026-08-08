class Solution {
public:

    int m, n;

    // DFS ka kaam:
    // (i,j) se destination tak koi path hai ya nahi
    // Agar path milta hai to us path ke saare cells ko 0 bhi kar deta hai
    bool dfs(vector<vector<int>>& grid, int i, int j) {

        // Grid ke bahar chale gaye
        // Ya current cell blocked hai
        if (i >= m || j >= n || grid[i][j] == 0)
            return false;

        // Destination mil gaya
        if (i == m - 1 && j == n - 1)
            return true;

        // Current cell ko erase kar do
        // Taaki ye path dobara use na ho
        grid[i][j] = 0;

        // Pehle Down try karo
        // Agar nahi mila to Right try karo
        return dfs(grid, i + 1, j) || dfs(grid, i, j + 1);
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {

        // Grid ka size
        m = grid.size();
        n = grid[0].size();

        // -------------------------
        // STEP-1
        // Pehle dekh lo path exist bhi karta hai ya nahi
        // -------------------------

        if (!dfs(grid, 0, 0))
            return true;

        // Agar yahan tak aaye hain
        // Matlab ek path mil gaya tha
        // Aur DFS us path ko erase bhi kar chuka hai

        // Source aur Destination ko erase nahi karna
        // Isliye unko wapas 1 bana do

        grid[0][0] = 1;
        grid[m - 1][n - 1] = 1;

        // -------------------------
        // STEP-2
        // Ab dubara path dhoondo
        // -------------------------

        // Agar second path nahi mila
        // To iska matlab sirf ek hi path tha
        // Aur usko erase karne se graph disconnect ho gaya
        // Answer = true

        // Agar second path mil gaya
        // To matlab do independent paths the
        // Answer = false

        return !dfs(grid, 0, 0);
    }
};