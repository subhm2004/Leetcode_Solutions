// class Solution {
// public:
//     int smallestNumber(int n) {
//         int k = 1;
//         while ((1 << k) - 1 < n) { // 2^k - 1
//             k++;
//         }
//         return (1 << k) - 1;
//     }
// };

class Solution {
public:
    int smallestNumber(int n) {
        int k = ceil(log2(n + 1));
        return (1 << k) - 1; 
    }
};