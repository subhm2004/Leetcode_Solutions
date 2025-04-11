class Solution {
public:
    bool is_symmetric(int num) {
        string s = to_string(num);
        int len = s.length();
        if (len % 2 != 0)
            return false;

        int left_sum = 0, right_sum = 0;
        for (int i = 0; i < len / 2; ++i)
            left_sum += s[i] - '0';
        for (int i = len / 2; i < len; ++i)
            right_sum += s[i] - '0';

        return left_sum == right_sum;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i)
            if (is_symmetric(i))
                ++count;
        return count;
    }
};
