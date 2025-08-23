class Solution {
public:
    long long flowerGame(int n, int m) {
        // Step 1: Odd/Even count
        long long odd_x = (n + 1) / 2;
        long long even_x = n / 2;
        long long odd_y = (m + 1) / 2;
        long long even_y = m / 2;

        // Step 2: Alice winning pairs
        return odd_x * even_y + even_x * odd_y;
    }
};
