// class Solution {
// public:
//     int findKthNumber(int n, int k) {
//         vector<string> num;
//         for (int i = 1; i <= n; i++) {
//             num.push_back(to_string(i));
//         }

//         sort(num.begin(), num.end());

//         return stoi(num[k - 1]); // k-1 because vector is 0-indexed
//     }
// };

class Solution {
public:
    int findKthNumber(int n, int k) {
        // Helper function jo do numbers ke beech ka gap calculate karega
        // lexicographical order me
        auto getGap = [&](long curr, long next) {
            long gap = 0;
            // Jab tak current number n se chhota hai, gap calculate karte raho
            while (curr <= n) {
                gap += min(static_cast<long>(n + 1), next) - curr;
                curr *=
                    10; // Child number tak aage badho (jaise 1 se 10, fir 100)
                next *= 10; // Next sibling tak aage badho
            }
            return gap;
        };

        long currNum = 1; // Sabse chhota number se start karo (1
                          // lexicographical order me sabse pehle aata hai)
        k--; // Kyunki hum 1 se start kar rahe hain, k ko zero-indexed adjust
             // kar do

        // Jab tak k-th number nahi milta, loop chalao
        while (k > 0) {
            long gap =
                getGap(currNum, currNum + 1); // Current aur next number ke
                                              // beech ka gap calculate karo

            if (gap <= k) {
                // Agar k-th number iss range ke baad aata hai, to next sibling
                // par jump karo
                currNum++; // Next sibling number par jao
                k -= gap;  // k ko gap ke size se ghata do
            } else {
                // Agar k-th number iss range ke andar hai, to tree me deep dive
                // karo (child number ki taraf jao)
                currNum *= 10; // Current number ka first child lo (jaise 1 se
                               // 10 par jao)
                k--;           // Ek number visit ho gaya, to k ko 1 se ghatao
            }
        }

        return currNum; // Final result, k-th number ko return karo
    }
};
