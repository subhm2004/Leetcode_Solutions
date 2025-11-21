class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0) return false;

    string str = to_string(x);

    int left = 0;
    int right = str.length() - 1;
     while (left < right) {
        if (str[left++] != str[right--]) {
            return false;
        }
    }

    return true;
}
};
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0 || (x % 10 == 0 && x != 0)) return false;

//         int reversedHalf = 0;
//         while (x > reversedHalf) {
//             reversedHalf = reversedHalf * 10 + x % 10;
//             x /= 10;
//         }

//         // Compare original half with reversed half (even and odd length cases)
//         return x == reversedHalf || x == reversedHalf / 10;
//     }
// };

