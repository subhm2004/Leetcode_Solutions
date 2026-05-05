class Solution {
public:
    vector<bool> isPrime;

    void sieve(int n) {
        isPrime.assign(n + 1, 1);  
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    int reverse_num(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    int sumOfPrimesInRange(int n) {
        int r = reverse_num(n);

        int L = min(n, r);
        int R = max(n, r);

        sieve(R);   

        int sum = 0;
        for (int i = L; i <= R; i++) {
            if (isPrime[i]) {
                sum += i;
            }
        }

        return sum;
    }
};