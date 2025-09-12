// class Solution {
// public:
//     int reinitializePermutation(int n) {
//         vector<int> perm(n), arr(n), original(n);

//         // Original permutation [0,1,2,...,n-1]
//         for (int i = 0; i < n; i++) {
//             perm[i] = i;
//             original[i] = i;
//         }

//         int count = 0;
//         while (true) {
//             count++;
//             for (int i = 0; i < n; i++) {
//                 if (i % 2 == 0) {
//                     arr[i] = perm[i / 2];
//                 } else {
//                     arr[i] = perm[n / 2 + (i - 1) / 2];
//                 }
//             }
//             perm = arr;

//             if (perm == original) return count;
//         }
//     }
// };


class Solution {
public:
    int reinitializePermutation(int n) {
        int count = 0;
        int pos = 1; // 0 toh apni jagah pe hi rehta hai, hum 1 se start karte hain

        while (true) {
            count++;
            if (pos % 2 == 0) {
                pos = pos / 2;
            } else {
                pos = n / 2 + (pos - 1) / 2;
            }
            if (pos == 1) break; // jab wapas 1 pe aaya matlab poora cycle complete
        }
        return count;
    }
};
