class Solution {
public:

    vector<int> sieve_of_erasthothenis(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) primes.push_back(i);
        }

        return primes;
    }

    // ---- your function ----
    void get_prime_factors(int n, const vector<int>& primes, set<int>& prime_factors) {

        for (int prime : primes) {
            if (prime * prime > n)
                break;

            if (n % prime == 0) {
                prime_factors.insert(prime);
                while (n % prime == 0) {
                    n /= prime;
                }
            }
        }

        if (n > 1) {
            prime_factors.insert(n);
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {

        vector<int> primes = sieve_of_erasthothenis(1000);

        set<int> prime_factors;   

        for (int x : nums) {
            get_prime_factors(x, primes, prime_factors);
        }

        return prime_factors.size();
    }
};
