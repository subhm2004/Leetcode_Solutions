class Solution {
public:
    int binary_search_sqrt(int num) {
        int left = 0;
        int right = num;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (1LL * mid * mid <= num) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    double sqrt_newton_rapson(double n) {
        const double eps = 1e-15;
        double x = 1;

        for (;;) {
            double nx = (x + n / x) / 2;
            if (abs(x - nx) < eps)
                break;
            x = nx;
        }

        return x;
    }
    int mySqrt(int x) {
        if (x == 0) return 0;
        // return binary_search_sqrt(x);
        return (int)sqrt_newton_rapson(x);
    }
};
