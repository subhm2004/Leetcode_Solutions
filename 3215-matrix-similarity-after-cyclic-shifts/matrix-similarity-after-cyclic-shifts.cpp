class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k %= n;  
        if (k == 0) return true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int new_idx;

                if (i % 2 == 0) {
                    // even row -> left shift
                    new_idx = (j + k) % n;
                } else {
                    // odd row -> right shift
                    new_idx = (j - k + n) % n;
                }

                if (mat[i][j] != mat[i][new_idx]) {
                    return false;
                }
            }
        }

        return true;
    }
};