class Solution {
public:
    // Base-k mein number ko convert karta hai aur check karta hai palindrome hai ya nahi
    bool is_Palindrome_In_BaseK(long long num, int k) {
        vector<int> digits;
        long long temp = num;
        
        // Number ko base-k digits mein convert karo
        while (temp > 0) {
            digits.push_back(temp % k);
            temp /= k;
        }
        
        // Check karo palindrome hai ya nahi
        int left = 0, right = digits.size() - 1;
        while (left < right) {
            if (digits[left] != digits[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    // Given length ke liye saare base-10 palindromes generate karta hai
    vector<long long> generatePalindromes(int length) {
        vector<long long> palindromes;
        
        if (length == 1) {
            // Single digit palindromes: 1, 2, 3, ..., 9
            for (int i = 1; i <= 9; i++) {
                palindromes.push_back(i);
            }
            return palindromes;
        }
        
        // Multi-digit palindromes generate karo
        int halfLength = (length + 1) / 2;  // First half ki length
        long long start = 1;
        for (int i = 1; i < halfLength; i++) {
            start *= 10;  // 10^(halfLength-1)
        }
        long long end = start * 10;  // 10^halfLength
        
        for (long long i = start; i < end; i++) {
            string half = to_string(i);
            string palindrome = half;
            
            // Second half banao by reversing first half
            if (length % 2 == 0) {
                // Even length: complete reverse
                reverse(half.begin(), half.end());
                palindrome += half;
            } else {
                // Odd length: reverse without middle digit
                reverse(half.begin(), half.end());
                palindrome += half.substr(1);
            }
            
            palindromes.push_back(stoll(palindrome));
        }
        
        return palindromes;
    }
    
    long long kMirror(int k, int n) {
        vector<long long> kMirrorNumbers;
        int length = 1;
        
        // Jab tak n k-mirror numbers nahi mil jaate
        while (kMirrorNumbers.size() < n) {
            // Current length ke saare base-10 palindromes generate karo
            vector<long long> palindromes = generatePalindromes(length);
            
            // Har palindrome ko check karo base-k mein bhi palindrome hai ya nahi
            for (long long palindrome : palindromes) {
                if (is_Palindrome_In_BaseK(palindrome, k)) {
                    kMirrorNumbers.push_back(palindrome);
                    
                    // Agar n numbers mil gaye to break karo
                    if (kMirrorNumbers.size() >= n) {
                        break;
                    }
                }
            }
            
            length++;  // Next length ke palindromes check karo
        }
        
        // First n k-mirror numbers ka sum calculate karo
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += kMirrorNumbers[i];
        }
        
        return sum;
    }
};

/*
OPTIMIZATION EXPLANATION (Hinglish):

1. BRUTE FORCE PROBLEM:
   - Pehle approach mein har number (1,2,3,4,5...) check kar rahe the
   - Ye bahut slow hai kyunki palindromes rare hote hain
   - Time complexity: O(num * log(num)) where num can be very large

2. OPTIMIZED APPROACH:
   - Pehle base-10 palindromes generate karte hain systematically
   - Phir sirf unko base-k mein check karte hain
   - Palindromes generate karna much faster hai

3. PALINDROME GENERATION:
   - Length 1: 1,2,3,4,5,6,7,8,9
   - Length 2: 11,22,33,44,55,66,77,88,99
   - Length 3: 101,111,121,131,...,191,202,212,...,999
   - Pattern: First half generate karo, second half mirror karo

4. BASE-K CHECK:
   - Number ko base-k digits mein convert karo
   - Array ko check karo palindrome hai ya nahi
   - Reverse string banane ki zarurat nahi

5. TIME COMPLEXITY:
   - Base-10 palindromes: O(10^(length/2)) per length
   - Base-k check: O(log_k(num)) per number
   - Overall: Much faster than brute force

EXAMPLE:
k=2, n=5
Length 1 palindromes: 1,2,3,4,5,6,7,8,9
- 1 in base-2: 1 (palindrome) ✓
- 2 in base-2: 10 (not palindrome) ✗
- 3 in base-2: 11 (palindrome) ✓
- 4 in base-2: 100 (not palindrome) ✗
- 5 in base-2: 101 (palindrome) ✓
- 6 in base-2: 110 (not palindrome) ✗
- 7 in base-2: 111 (palindrome) ✓
- 8 in base-2: 1000 (not palindrome) ✗
- 9 in base-2: 1001 (palindrome) ✓

First 5 k-mirror numbers: 1,3,5,7,9
Sum = 1+3+5+7+9 = 25
*/