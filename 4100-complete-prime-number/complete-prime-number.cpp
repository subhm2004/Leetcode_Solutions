class Solution {
public:
     bool isPrime(long long n) {
        if (n < 2) return false;

        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        // Check all prefixes
        for (int i = 1; i <= n; i++) {
            long long prefix = stoll(s.substr(0, i));
            if (!isPrime(prefix)) return false;
        }

        // Check all suffixes
        for (int i = 0; i < n; i++) {
            long long suffix = stoll(s.substr(i));
            if (!isPrime(suffix)) return false;
        }

        return true;   
    }
};
