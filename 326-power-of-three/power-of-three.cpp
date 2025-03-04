// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if (n <= 0) return false;
//         while (n % 3 == 0) {
//             n /= 3;
//         }
//         return n == 1;
//     }
// };
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;   // Base case: 1 is a power of 3
        if (n <= 0 || n % 3 != 0) return false; // If n is non-positive or not divisible by 3
        
        return isPowerOfThree(n / 3); // Recursive call
    }
};
