class Solution {
public:
    int solveRE(const vector<vector<int>>& books, int shelf_width, int i) {
        // Agar saare books place ho gaye to height 0 return karo
        if (i >= books.size())
            return 0;

        int min_height = INT_MAX; // Minimum height track karne ke liye
        int sum_thickness = 0,
            max_height =
                0; // Ek shelf ka thickness aur max height track karne ke liye

        // i se lekar books ko place karne ka try karenge
        for (int j = i; j < books.size(); ++j) {
            sum_thickness +=
                books[j][0]; // Shelf ka total thickness badh raha hai
            if (sum_thickness >
                shelf_width) // Agar width exceed ho gayi to break kar do
                break;
            max_height =
                max(max_height,
                    books[j][1]); // Current shelf ki max height update karo
            min_height = min(
                min_height,
                max_height +
                    solveRE(books, shelf_width,
                            j + 1)); // Minimum possible height calculate karo
        }

        return min_height; // Optimal answer return karo
    }

    int solveME(const vector<vector<int>>& books, int shelf_width, int i,
                vector<int>& dp) {
        if (i == books.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int min_height = INT_MAX;
        int sum_thickness = 0, max_height = 0;

        for (int j = i; j < books.size(); ++j) {
            sum_thickness += books[j][0];
            if (sum_thickness > shelf_width)
                break;
            max_height = max(max_height, books[j][1]);
            min_height =
                min(min_height,
                    max_height + solveME(books, shelf_width, j + 1, dp));
        }

        return dp[i] = min_height;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(books.size(), -1);
        return solveME(books, shelf_width, 0, dp);
    }
};
