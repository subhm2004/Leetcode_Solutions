class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while (num != 0) {
            if (num % 2 == 0) {
                num /= 2;  // Divide by 2 if even
            } else {
                num -= 1;  // Subtract 1 if odd
            }
            steps++;
        }
        return steps;
    }
};