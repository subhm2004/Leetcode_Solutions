class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        // Step 1: Extract digits from n
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int m = digits.size();
        int max_Prod = 0;

        // Step 2: Try all pairs 
        for (int i = 0; i < m; ++i) {
            for (int j = i+1; j < m; ++j) {
                max_Prod = max(max_Prod, digits[i] * digits[j]);
            }
        }

        return max_Prod;
    }
};
