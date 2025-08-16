class Solution {
public:
     int ceil_division(int a, int b) {
        return (a + b - 1) / b;
    }

    int minSensors(int n, int m, int k) {
        int block = 2 * k + 1; // ek sensor ka cover area (rows/cols)
        
        int rows_needed = ceil_division(n, block);
        int cols_needed = ceil_division(m, block);
        
        return rows_needed * cols_needed;
    }
};
