   class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();  // Matrix ka size (n x n) — yaani rows and columns dono n hain

        // Har row aur column ke liye check karenge
        for (int i = 0; i < n; ++i) {
            vector<int> rowCount(n + 1, 0);  // Row ke liye count array (1 se n tak ke numbers ke liye)
            vector<int> colCount(n + 1, 0);  // Column ke liye count array

            // Row aur column ke har element ko traverse karo
            for (int j = 0; j < n; ++j) {
                rowCount[matrix[i][j]]++;  // Row i ke element ka count badhao
                colCount[matrix[j][i]]++;  // Column i ke element ka count badhao
            }

            // Check karo koi number 2 baar toh nahi aaya
            for (int k = 1; k <= n; ++k) {
                if (rowCount[k] > 1 || colCount[k] > 1) {
                    return false;  // Agar duplicate mila, toh matrix valid nahi hai
                }
            }
        }

        return true;  // Agar har row aur column mein unique 1 se n tak number mile, toh matrix valid hai
    }
};


// class Solution {
// public:
//     bool checkValid(vector<vector<int>>& matrix) {
//         int n = matrix.size();

//         for (int i = 0; i < n; ++i) {
//             unordered_set<int> rowSet, colSet;

//             for (int j = 0; j < n; ++j) {
//                 // Check row and column elements
//                 if (rowSet.count(matrix[i][j]) || colSet.count(matrix[j][i])) {
//                     return false;
//                 }
//                 rowSet.insert(matrix[i][j]);
//                 colSet.insert(matrix[j][i]);
//             }
//         }

//         return true;
//     }
// };
