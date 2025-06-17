class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), m = baskets.size(), count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (baskets[j] >= fruits[i]) {
                    baskets[j] = INT_MIN; // Mark basket as used
                    ++count;         // Count placed fruit
                    break;         // Move to the next fruit
                }
            }
        }
        
        return n - count; // Return the number of unplaced fruits
    }
};



