class Solution {
public:
    string fractionAddition(string expression) {
        istringstream iss(expression);  // Create an input stream from the string
        char _;  // This will hold the '/' character (unused)
        int a;  // This will hold the numerator of the current fraction
        int b;  // This will hold the denominator of the current fraction
        int A = 0;  // The total numerator of the sum of fractions
        int B = 1;  // The total denominator of the sum of fractions
        
        // While we can extract a fraction (numerator and denominator)
        while (iss >> a >> _ >> b) {
            // Step 1: Adding fractions
            A = A * b + a * B;  // Add fractions: (A/B) + (a/b) = (A*b + a*B) / (B*b)
            B *= b;  // Multiply the denominators (B * b)

            // Step 2: Simplifying the fraction
            const int g = abs(__gcd(A, B));  // Find the greatest common divisor (gcd) of the numerator and denominator
            A /= g;  // Divide the numerator by the gcd
            B /= g;  // Divide the denominator by the gcd
        }

        // Step 3: Return the result as a string in the form "numerator/denominator"
        return to_string(A) + "/" + to_string(B);
    }
};
