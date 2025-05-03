class Solution {
public:
    string generateTheString(int n) {
        if (n % 2 == 1) {
            return string(n, 'a'); // 'a' n times
        } else {
            return string(n - 1, 'a') + 'b'; // 'a' (n-1) times + 'b'
        }
    }
};
