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
        if (n == 1) return true;      // 3^0 = 1
        if (n <= 0 || n % 3 != 0) return false;
        return isPowerOfThree(n / 3); // har step me 3 se divide karo
    }
};
