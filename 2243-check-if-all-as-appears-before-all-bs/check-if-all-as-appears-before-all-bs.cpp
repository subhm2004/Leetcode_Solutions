// class Solution {
// public:
//     bool checkString(string s) {
//         bool check = false;
//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == 'b') {
//                 check = true;
//             }
//             if (check && s[i] == 'a') {
//                 return false;
//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool checkString(string s) { return s.find("ba") == string::npos; }
};