class Solution {
public:
    string convertToBaseN(int num, int base) {
        if (base < 2) {
            throw invalid_argument("Base must be at least 2.");
        }

        if (num == 0) {
            return "0";
        }

        const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string result;

        bool isNegative = num < 0;
        num = abs(num);

        while (num > 0) {
            result = digits[num % base] + result;
            num /= base;
        }

        if (isNegative) {
            result = "-" + result;
        }

        return result;
    }
    string convertToBase7(int num) {
        string s = convertToBaseN(num, 7);
        return s;
    }
};