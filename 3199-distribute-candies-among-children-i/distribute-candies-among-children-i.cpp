// class Solution {
// public:
//     long nCk(int n, int k) {
//         long res = 1;
//         for (int i = 1; i <= k; ++i)
//             res = res * (n - i + 1) / i;
//         return res;
//     }

//     long ways(int n) {
//         if (n < 0)
//             return 0;
//         return nCk(n + 2,
//                    2); // Using stars and bars method (Beggar's coin method )
//     }

//     int distributeCandies(int n, int limit) {
//         int limitPlusOne = limit + 1;
//         long oneChildExceedsLimit = ways(n - limitPlusOne);
//         long twoChildrenExceedLimit = ways(n - 2 * limitPlusOne);
//         long threeChildrenExceedLimit = ways(n - 3 * limitPlusOne);
//         // Principle of Inclusion-Exclusion
//         return ways(n) - 3 * oneChildExceedsLimit + 3 * twoChildrenExceedLimit -
//                threeChildrenExceedLimit;
//     }
// };

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int ways = 0;

        for (int x1 = 0; x1 <= min(n, limit); ++x1) {
            for (int x2 = 0; x2 <= min(n - x1, limit); ++x2) {
                int x3 = n - x1 - x2;
                if (x3 >= 0 && x3 <= limit) {
                    ++ways;
                }
            }
        }

        return ways;
    }
};