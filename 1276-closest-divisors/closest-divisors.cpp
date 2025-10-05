class Solution {
public:
    vector<int> find_closest_divisor_pair(int n) {
        int a = 1, b = n;
        int sqrt_n = sqrt(n);
        for (int i = 1; i <= sqrt_n; i++) {
            if (n % i == 0) {
                int j = n / i;
                if (abs((long long)i - j) < abs((long long)a - b)){
                    a = i;
                    b = j;
                }
            }
        }
        return {a, b};
    }

    vector<int> closestDivisors(int num) {
        vector<int> pair1 = find_closest_divisor_pair(num + 1);
        vector<int> pair2 = find_closest_divisor_pair(num + 2);
        
        if (abs(pair1[0] - pair1[1]) <= abs(pair2[0] - pair2[1]))
            return pair1;
        return pair2;
    }
};
