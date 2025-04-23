class Solution {
public:
    int sum_of_digits(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> mp; 
        // key   = digit sum of a number
        // value = how many numbers had that digit sum

        int maxSize = 0;
        int count = 0;

        for (int num = 1; num <= n; num++) {
            int digitsSum = sum_of_digits(num);

            mp[digitsSum]++;
            if (mp[digitsSum] == maxSize) {
                count++;
            } 
            //This condition only triggers when a new max group size is found.
            else if (mp[digitsSum] > maxSize) {
                maxSize = mp[digitsSum];
                count = 1;
            }
        }

        return count;
    }
};
