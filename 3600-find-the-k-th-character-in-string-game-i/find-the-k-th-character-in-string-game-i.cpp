// class Solution {
// public:
//     char kthCharacter(int k) {
//         string s = "a";
//         while (s.size() < k) {
//             string temp = "";
//             for (int i = 0; i < s.size(); i++) {
//                 // Get the next character cyclically (z -> a)
//                 char next = (s[i] == 'z') ? 'a' : s[i] + 1;
//                 temp += next;
//             }
//             s += temp;
//         }
//         return s[k - 1]; // 1-based indexing
//     }
// };
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Solution {
public:
    char kthCharacter(int k) {
        // k se p char ki value deni h lekin dekha jaye to sari values satarting me 1 (a) se hi nikli h lekin ab k pr h to shift ho gya k-1 ka lekin jo shift ho rha h wo two ki power me ho rha hai to jitni shift k andar set bits h use add krre hai a me 
        int shifts = __builtin_popcount(k - 1); // counts no. of 1s in binary rep of k-1
        return 'a' + shifts;
    }
};
