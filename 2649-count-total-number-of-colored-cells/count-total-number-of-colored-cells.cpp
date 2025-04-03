class Solution {
public:
    long long coloredCells(int n) {
        long long sum = 1;  // Start with the initial center cell
        
        for (int i = 1; i < n; i++) {
            sum += 4 * i;  // Add 4 * i new cells at each step
        }

        return sum;
    }
};
