class Solution {
public:
    int sum_if_four_divisors(int num) {
        int divisor_count = 0;
        int divisor_sum = 0;

        for (int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                if (i * i == num) { // Agar i ek perfect square divisor hai
                    divisor_count++;
                    divisor_sum += i;
                } else { // i aur num / i dono divisors hain
                    divisor_count += 2;
                    divisor_sum += i + num / i;
                }
            }
        }

        return divisor_count == 4 ? divisor_sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {
            sum += sum_if_four_divisors(num);
        }

        return sum;
    }
};
