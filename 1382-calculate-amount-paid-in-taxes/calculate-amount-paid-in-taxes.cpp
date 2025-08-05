class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        // Total tax amount jo calculate karna hai
        double tax = 0.0;
        
        // Previous bracket ka upper limit track karne ke liye
        // Initially 0 hai kyunki pehle bracket se pehle koi income nahi hai
        int prev_upper = 0;
        
        // Har bracket ko iterate karte hain
        for (const auto& bracket : brackets) {
            // Current bracket ka upper limit aur tax percentage
            int upper = bracket[0];    // Bracket ka upper limit
            int percent = bracket[1];  // Tax percentage for this bracket
            
            // Agar income already previous bracket se kam ya equal hai
            // toh aage calculate karne ki zarurat nahi
            if (income <= prev_upper) break;
            
            // Current bracket mein kitni income taxable hai
            // min(income, upper) isliye kyunki agar income bracket se kam hai
            // toh sirf utni income pe tax lagega, warna pura bracket fill hoga
            int taxable_income = min(income, upper) - prev_upper;
            
            // Tax calculate karte hain: (taxable_income * percentage) / 100
            tax += (taxable_income * percent) / 100.0;
            
            // Next iteration ke liye previous upper limit update karte hain
            prev_upper = upper;
        }
        
        return tax;
    }
};

/*
DETAILED DRY RUN:
================

Example: brackets = [[3,50], [7,10], [12,25]], income = 10

Step-by-step execution:

Initial values:
- tax = 0.0
- prev_upper = 0
- income = 10

Iteration 1: bracket = [3, 50]
- upper = 3, percent = 50
- income (10) > prev_upper (0), so continue
- taxable_income = min(10, 3) - 0 = 3 - 0 = 3
- tax += (3 * 50) / 100.0 = 0.0 + 1.5 = 1.5
- prev_upper = 3

Iteration 2: bracket = [7, 10]  
- upper = 7, percent = 10
- income (10) > prev_upper (3), so continue
- taxable_income = min(10, 7) - 3 = 7 - 3 = 4
- tax += (4 * 10) / 100.0 = 1.5 + 0.4 = 1.9
- prev_upper = 7

Iteration 3: bracket = [12, 25]
- upper = 12, percent = 25  
- income (10) > prev_upper (7), so continue
- taxable_income = min(10, 12) - 7 = 10 - 7 = 3
- tax += (3 * 25) / 100.0 = 1.9 + 0.75 = 2.65
- prev_upper = 12

Final Result: tax = 2.65

Explanation:
- Bracket 1 (0-3): 3 units at 50% = 1.5
- Bracket 2 (3-7): 4 units at 10% = 0.4  
- Bracket 3 (7-10): 3 units at 25% = 0.75
- Total: 1.5 + 0.4 + 0.75 = 2.65

Ye progressive tax system hai jahan different income ranges pe 
different tax rates apply hote hain.
*/