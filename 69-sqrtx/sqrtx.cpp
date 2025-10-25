class Solution {
public:
    int mySqrt(int num) {
        int low = 1;
        int high = num;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (1LL * mid * mid <= num) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
