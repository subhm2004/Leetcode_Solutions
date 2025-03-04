// class Solution {
// public:
//     bool checkPowersOfThree(int n) {
//         long power = 1;
        
//         // Find the smallest power of 3 that is ≥ n
//         for (int i = 0; power < n; i++) {
//             power = pow(3, i);
//         }

//         // Try subtracting distinct powers of 3
//         for (; power > 0; power /= 3) {
//             if (n >= power) {
//                 n -= power;
//             }
//         }

//         return n == 0;
//     }
// };
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) return false; // If a digit 2 appears, return false
            n /= 3;
        }
        return true;
    }
};
