// class Solution {
// public:
//     int kthFactor(int n, int k) {
//         int count = 0;
//         for (int i = 1; i <= n; ++i) {
//             if (n % i == 0) {
//                 count++;
//                 if (count == k) {
//                     return i;
//                 }
//             }
//         }
//         return -1; // agar k factors nahi mile
//     }
// };

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;

        // Step 1: Collect all factors of n
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                factors.push_back(i);
            }
        }

        // Step 2: Check if k-th factor exists
        if (k <= factors.size()) {
            return factors[k - 1];  // 0-based indexing
        } else {
            return -1;  // Not enough factors
        }
    }
};
