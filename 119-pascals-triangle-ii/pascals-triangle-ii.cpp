class Solution {
public:
    long long nCr(int n, int r) {
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}


    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);  // Initialize row with size (rowIndex + 1)
        long long val = 1;
        row[0] = 1;  // First value is always 1

        // Use the formula: C(n, k) = C(n, k-1) * (n - k + 1) / k
        for (int k = 1; k <= rowIndex; ++k) {
            val = val * (rowIndex - k + 1) / k;
            row[k] = val;  // Store the current value
        }

        return row;
    }
};
