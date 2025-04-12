class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> unique_sorted_Palindromes;

        int half_length = (n + 1) / 2;
        int start = pow(10, half_length - 1);
        int end = pow(10, half_length) - 1;

        // Step 1: Generate palindromes of length `n` and divisible by `k`
        for (int num = start; num <= end; num++) {
            string left = to_string(num);
            string right = left.substr(0, n % 2 == 0 ? half_length : half_length - 1);
            reverse(right.begin(), right.end());

            string palindrome = left + right;

            long long number = stoll(palindrome);
            if (number % k != 0) continue;

            sort(palindrome.begin(), palindrome.end());
            unique_sorted_Palindromes.insert(palindrome);
        }

        // Step 2: Precompute factorials from 0! to 10!
        vector<long long> fact(11, 1);
        for (int i = 1; i <= 10 ; i++)
            fact[i] = fact[i - 1] * i;

        // Step 3: Count valid permutations of each unique sorted digit string
        long long ans = 0;
        for (auto& s : unique_sorted_Palindromes) {
            vector<int> digit_count(10, 0);
            for (auto &ch : s)
                digit_count[ch - '0']++;

            int len = s.length();
            int zeros = digit_count[0];
            int nonZeros = len - zeros;

            long long permutation = nonZeros * fact[len - 1]; // first digit ≠ 0

            for (auto& count : digit_count)
                permutation /= fact[count];

            ans += permutation;
        }

        return ans;
    }
};
