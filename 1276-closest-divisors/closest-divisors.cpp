class Solution {
public:
    vector<int> find_closest_divisor_pair(int n) {
        int a = 1, b = n; // Initialize divisors with default 1 and n
        int sqrt_n = sqrt(n); // We only need to check divisors up to sqrt(n)
        for (int i = 1; i <= sqrt_n; i++) { // Loop from 1 to sqrt(n)
            if (n % i == 0) { // If i divides n exactly
                int j = n / i; // j is the corresponding paired divisor
                if (abs((long long)i - j) < abs((long long)a - b)){ // If this pair has smaller difference than previous
                    a = i; // Update a
                    b = j; // Update b
                }
            }
        }
        return {a, b}; // Return the pair of divisors with minimum absolute difference
    }
    vector<int> closestDivisors(int num) {
        vector<int> pair1 = find_closest_divisor_pair(num + 1); // Find closest divisors of num + 1
        vector<int> pair2 = find_closest_divisor_pair(num + 2); // Find closest divisors of num + 2
        
        // Compare absolute difference of the two pairs
        // Return the pair which has smaller difference
        if (abs(pair1[0] - pair1[1]) <= abs(pair2[0] - pair2[1]))
            return pair1;
        return pair2;
    }
};