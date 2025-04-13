class Solution {                    // Code_story_with_MIK
public:
    long long countGoodIntegers(int n, int k) {
        // Unique sorted palindromes ko store karne ke liye unordered_set ka use kar rahe hain
        unordered_set<string> unique_sorted_Palindromes;

        // Half length calculate kar rahe hain (agar n odd hai toh ek extra digit lena hai)
        int half_length = (n + 1) / 2;
        int start = pow(10, half_length - 1); // Palindrome number ka start range
        int end = pow(10, half_length) - 1;   // Palindrome number ka end range

        // Step 1: Palindromes generate kar rahe hain jo length `n` ke hain aur k se divisible hain
        for (int num = start; num <= end; num++) {
            string left = to_string(num);  // Left part ko string mein convert kar rahe hain
            string right = left.substr(0, n % 2 == 0 ? half_length : half_length - 1);  // Right part ko reverse karna hai
            reverse(right.begin(), right.end()); // Right part ko reverse kar rahe hain

            string palindrome = left + right; // Dono parts ko combine karke palindrome banate hain

            long long number = stoll(palindrome); // Palindrome ko integer mein convert karte hain
            if (number % k != 0) continue; // Agar palindrome k se divisible nahi hai toh next number check karte hain

            // Palindrome ko sort kar rahe hain taaki unique permutations count kar sakein
            sort(palindrome.begin(), palindrome.end());
            unique_sorted_Palindromes.insert(palindrome); // Unique sorted palindrome ko set mein insert karte hain
        }

        // Step 2: Factorials ko precompute kar rahe hain (0! se leke 10! tak)
        vector<long long> fact(12, 1);
        for (int i = 1; i <= 11; i++)
            fact[i] = fact[i - 1] * i;  // Factorial calculation

        // Step 3: Har unique sorted palindrome ka valid permutations count kar rahe hain
        long long ans = 0;
        for (auto& s : unique_sorted_Palindromes) {
            vector<int> digit_count(10, 0);  // Digits ka count rakhne ke liye array

            for (auto &ch : s)
                digit_count[ch - '0']++;  // Har digit ka count increase kar rahe hain

            int len = s.length();
            int zeros = digit_count[0];  // Zero digits ka count
            int nonZeros = len - zeros;  // Non-zero digits ka count

            // Permutation calculate kar rahe hain (first digit 0 nahi ho sakta)
            long long permutation = nonZeros * fact[len - 1]; // First digit ≠ 0

            for (auto& count : digit_count)
                permutation /= fact[count]; // Repeated digits ke liye factorial se divide kar rahe hain

            ans += permutation; // Total valid permutations ko add karte jaa rahe hain
        }

        return ans; // Final answer return karte hain
    }
};
