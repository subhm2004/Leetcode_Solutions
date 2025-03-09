class Solution {
public:
    vector<bool> sieveEratosthenes(int n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;
            }
        }
        return isPrime;
    }

    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<bool> isPrime = sieveEratosthenes(n);
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i])
                ++count;
        }
        return count;
    }
};
