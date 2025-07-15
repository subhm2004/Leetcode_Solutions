class Solution {
public:
    // GCD nikalne ka function
    int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    // First digit nikalne ka function
    int first_digit(int a) {
        while (a >= 10) {
            a /= 10;
        }
        return a;
    }

    // Last digit nikalne ka function
    int last_digit(int a) {
        return a % 10;
    }

     int countBeautifulPairs(vector<int>& arr) {
        int count = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            int d1 = first_digit(arr[i]);

            for (int j = i + 1; j < n; ++j) {
                int d2 = last_digit(arr[j]);

                if (GCD(d1, d2) == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
