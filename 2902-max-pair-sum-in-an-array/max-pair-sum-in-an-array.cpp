class Solution {
public:
    //  kisi number ka largest digit nikalne ke liye
    int maximum_digit(int num) {
        int maxDigit = 0;
        while (num > 0) {
            maxDigit = max(maxDigit, num % 10);
            num /= 10;
        }
        return maxDigit;
    }

    int maxSum(vector<int>& nums) {
        // Har digit (0-9) ke liye maximum number store karne ke liye
        unordered_map<int, int> mp; // digit = key ans maximum_number = value

        int max_sum = -1;

        for (int num : nums) {
            int d = maximum_digit(num);  // current number ka max digit nikaalo

            // Agar pehle se koi number mila hai jiski max digit d thi
            if (mp.count(d)) {
                // Sum kro dono ka
                int sum = mp[d] + num;
                max_sum = max(max_sum, sum);
            }

            // Update karo max number for this digit d
            mp[d] = max(mp[d], num);
        }

        return max_sum;
    }
};
