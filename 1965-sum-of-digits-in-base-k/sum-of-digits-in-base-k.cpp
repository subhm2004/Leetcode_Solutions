class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;

        while (n) {
            sum += n % k;
            n /= k;
        }

        return sum;
    }
};


// class Solution {
// public:
//     string convertToBaseN(int num, int base) {
//         if (base < 2) {
//             throw invalid_argument("Base must be at least 2.");
//         }

//         if (num == 0) {
//             return "0";
//         }

//         const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//         string result;

//         bool isNegative = num < 0;
//         num = abs(num);

//         while (num > 0) {
//             result = digits[num % base] + result;
//             num /= base;
//         }

//         if (isNegative) {
//             result = "-" + result;
//         }

//         return result;
//     }

//     int sumOfDigits(int num) {
//         int sum = 0;
//         while (num != 0) {
//             sum += num % 10; // get the last digit
//             num /= 10;       // remove the last digit
//         }
//         return sum;
//     }

//     int sumBase(int n, int k) {
//         int num = stoi(convertToBaseN(n, k));
//         return sumOfDigits(num);
//     }
// };

