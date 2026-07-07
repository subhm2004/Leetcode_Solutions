class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string t = "";

        // Step 1: Collect non-zero digits
        for (char c : s) {
            if (c != '0') t += c;
        }

        // If no non-zero digits → x = 0 → return 0
        if (t.empty()) return 0;

        // Convert t to integer x
        long long x = stoll(t);

        // Step 2: Digit sum
        long long digit_sum = 0;
        for (char c : t) digit_sum += (c - '0');

        // Step 3: Return x * sum
        return x * digit_sum;
    }
};
