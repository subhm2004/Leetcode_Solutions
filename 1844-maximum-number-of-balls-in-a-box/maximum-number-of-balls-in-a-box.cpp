class Solution {
public:
    int digit_sum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countBalls(int low, int high) {
        int max_Digit_Sum = 9 * 5; // for maximum 99999
        vector<int> count(max_Digit_Sum + 1, 0);
        int ans = 0;

        for (int num = low; num <= high; num++) {
            int s = digit_sum(num);
            count[s]++;
            ans = max(ans, count[s]);
        }

        return ans;
    }
};
