class Solution {
public:
    int sumOfSquares(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10; 
            sum += digit * digit;  
            n /= 10;  
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int, bool> visited;

        while (n != 1) {
            if (visited[n]) 
                return false;
            
            visited[n] = true;
            n = sumOfSquares(n); 
        }

        return true;  
    }
};


// class Solution {
// public:
//     // Har digit ka square sum calculate karne ka function
//     int sumOfSquares(int n) {
//         int sum = 0;
//         while (n) {
//             int digit = n % 10; // Last digit nikalna
//             sum += digit * digit; // Square add karna
//             n /= 10; // Ek digit chhoti karna
//         }
//         return sum;
//     }

//     bool isHappy(int n) {
//         int slow = n, fast = n;

//         do {
//             slow = sumOfSquares(slow); // Slow ek step move karega
//             fast = sumOfSquares(sumOfSquares(fast)); // Fast do step move karega
//         } while (slow != fast); // Jab tak cycle detect nahi hoti

//         return slow == 1; // Agar 1 mila toh happy number hai
//     }
// };
