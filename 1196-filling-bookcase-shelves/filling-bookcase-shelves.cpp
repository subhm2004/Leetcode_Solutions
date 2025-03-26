class Solution {
 public:
 
int solveRE(const vector<vector<int>>& books, int shelfWidth, int i) {
  // Agar saare books place ho gaye to height 0 return karo
  if (i == books.size())
    return 0;

  int minHeight = INT_MAX; // Minimum height track karne ke liye
  int sumThickness = 0, maxHeight = 0; // Ek shelf ka thickness aur max height track karne ke liye

  // i se lekar books ko place karne ka try karenge
  for (int j = i; j < books.size(); ++j) {
    sumThickness += books[j][0]; // Shelf ka total thickness badh raha hai
    if (sumThickness > shelfWidth) // Agar width exceed ho gayi to break kar do
      break;
    maxHeight = max(maxHeight, books[j][1]); // Current shelf ki max height update karo
    minHeight = min(minHeight, maxHeight + solveRE(books, shelfWidth, j + 1)); // Minimum possible height calculate karo
  }

  return minHeight; // Optimal answer return karo
}

  int solveME(const vector<vector<int>>& books, int shelfWidth, int i, vector<int>& dp) {
    if (i == books.size())
      return 0;
    if (dp[i] != -1)
      return dp[i];

    int minHeight = INT_MAX;
    int sumThickness = 0, maxHeight = 0;

    for (int j = i; j < books.size(); ++j) {
      sumThickness += books[j][0];
      if (sumThickness > shelfWidth)
        break;
      maxHeight = max(maxHeight, books[j][1]);
      minHeight = min(minHeight, maxHeight + solveME(books, shelfWidth, j + 1, dp));
    }

    return dp[i] = minHeight;
  }

  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    vector<int> dp(books.size(), -1);
    return solveME(books, shelfWidth, 0, dp);
  }
};
