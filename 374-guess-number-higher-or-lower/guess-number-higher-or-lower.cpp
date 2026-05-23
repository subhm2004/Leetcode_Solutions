class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = guess(mid);

            if (val == -1) {
                r = mid - 1;
            } else if (val == 1) {
                l = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};