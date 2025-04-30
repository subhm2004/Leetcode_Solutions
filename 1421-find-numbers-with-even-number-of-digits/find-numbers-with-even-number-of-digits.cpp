class Solution {
public:
    // method_ 1: Using While Loop (Manual digit counting)
    int method_1( vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            int digits = 0;
            int n = num;
            if (n == 0) digits = 1;
            while (n != 0) {
                n /= 10;
                digits++;
            }
            if (!(digits & 1)) count++;
        }
        return count;
    }

    // method_ 2: Using to_string().length()
    int method_2(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if (to_string(num).length() % 2 == 0)
                count++;
        }
        return count;
    }

    // method_ 3: Using log10 (mathematical way)
    int method_3(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            int digits = (num == 0) ? 1 : (int)log10(num) + 1;
            if (digits % 2 == 0)
                count++;
        }
        return count;
    }

    // method_ 4: Using ceil(log10(num+1)) approach
    int method_4(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            int digits = (num == 0) ? 1 : (int)ceil(log10(num + 1));
            if (digits % 2 == 0)
                count++;
        }
        return count;
    }

    // method_ 5: Constant-time check using ranges
    int method_5(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if ((10 <= num && num <= 99) ||
                (1000 <= num && num <= 9999) ||
                (100000 <= num && num <= 999999)) {
                count++;
            }
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        return method_5(nums);
    }
};