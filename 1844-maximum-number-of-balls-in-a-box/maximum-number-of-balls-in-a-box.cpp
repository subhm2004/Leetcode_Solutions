class Solution {
public:
    int getDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }
    int countBalls(int low, int high) {
        int max_Digit_Sum = 9 * 5; // 99999
        int ans = 0;
        vector<int> count(max_Digit_Sum + 1);

        for (int num = low; num <= high; num++)
            ans = max(ans, ++count[getDigitSum(num)]);

        return ans;
    }
};