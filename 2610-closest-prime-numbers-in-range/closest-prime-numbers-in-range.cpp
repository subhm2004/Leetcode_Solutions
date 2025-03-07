class Solution {
public:
    // Function jo simple sieve ka use karke sqrt(n) tak ke saare prime numbers find karega
    vector<int> simpleSieve(int limit) {
        vector<bool> isPrime(limit + 1, true); // Pehle sabko prime maan lo
        vector<int> primes; // Prime numbers ko store karne ke liye vector

        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) { // Agar number prime hai to use store karo
                primes.push_back(i);
                // Uske sabhi multiples ko mark kar do as non-prime
                for (int j = i * i; j <= limit; j += i)
                    isPrime[j] = false;
            }
        }
        return primes; // Saare primes return kar do
    }

    // Function jo segmented sieve ka use karke [left, right] range ke andar primes dhoondega
    vector<int> segmentedSieve(int left, int right) {
        if (left < 2) left = 2;  // 2 se chhoti values ko 2 kar do kyunki prime 2 se start hote hain
        int limit = sqrt(right); // Sieve ke liye limit nikal lo

        // Step 1: Pehle sqrt(right) tak ke small primes dhoond lo
        vector<int> basePrimes = simpleSieve(limit);

        // Step 2: In small primes ka use karke [left, right] range me primes mark karo
        vector<bool> isPrime(right - left + 1, true);

        for (int prime : basePrimes) {
            int start = max(prime * prime, (left + prime - 1) / prime * prime); 
            // Prime ke multiples ko mark karo as non-prime
            for (int j = start; j <= right; j += prime)
                isPrime[j - left] = false;
        }

        // Step 3: Jo bhi prime bach gaye unko store kar lo
        vector<int> primes;
        for (int i = 0; i < isPrime.size(); i++)
            if (isPrime[i])
                primes.push_back(left + i);

        return primes; // Saare primes return kar do
    }

    // Function jo closest prime pair ko find karega given range [left, right] me
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = segmentedSieve(left, right); // Pehle primes find karo
        if (primes.size() < 2) return {-1, -1}; // Agar 2 se kam primes mile to valid pair nahi hai

        int minDiff = INT_MAX; // Minimum difference store karne ke liye
        vector<int> result = {-1, -1}; // Final answer ke liye pair

        // Saare primes ko check karo aur jo sabse chhota difference de use store karo
        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }
        return result; // Closest prime pair return karo
    }
};
