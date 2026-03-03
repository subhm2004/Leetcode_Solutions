class Solution {
public:
    int reverse(int x) {

        // Step 1: Integer ko string me convert karo
        string s = to_string(x);

        // Step 2: Negative handle karo
        bool is_negative = false;
        if (s[0] == '-') {
            is_negative = true;
            s = s.substr(1);   // '-' hata do
        }

        // Step 3: String reverse karo
        std::reverse(s.begin(), s.end());

        // Step 4: Leading zeros remove ho jayenge automatically stoll se
        long long num = stoll(s);

        if (is_negative) {
            num = -num;
        }

        // Step 5: Overflow check
        if (num > INT_MAX || num < INT_MIN)
            return 0;

        return (int)num;
    }
};