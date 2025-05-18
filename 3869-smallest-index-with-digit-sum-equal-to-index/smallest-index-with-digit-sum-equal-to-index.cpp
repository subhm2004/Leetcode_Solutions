class Solution {
public:
    int sum_Of_Digits(int num) {
        int sum = 0;
        num = abs(num);  // handle negative numbers
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (sum_Of_Digits(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};
