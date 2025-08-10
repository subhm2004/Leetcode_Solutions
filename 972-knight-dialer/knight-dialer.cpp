/*
===========================================
KNIGHT DIALER PROBLEM - COMPLETE BREAKDOWN
===========================================

Phone keypad layout (yaad rakhna ye):
1 2 3
4 5 6
7 8 9
  0

Knight chess piece ki tarah L-shape move karta hai:
- 2 squares ek direction + 1 square perpendicular direction
- Ya 1 square ek direction + 2 squares perpendicular direction
*/

class Solution {
public:
    // Line 1: MOD value define kiya - large numbers ko handle karne ke liye
    // Kyunki answer bahut bada ho sakta hai, isliye 10^9+7 se divide kar dete hain
    const int MOD = 1e9 + 7;
    
    /* Line 2-13: YE SABSE IMPORTANT PART HAI!
       moves array - har index pe vector hai jo batata hai ki us digit se kahan ja sakte hain
       
       Ye kaise pata kiya? 
       - Knight ka L-shaped move manually calculate kiya har digit ke liye
       - Example: 0 se (row 3, col 1) se knight kahan ja sakta hai?
         * Up-up-left: invalid (bahar chala gaya)
         * Up-up-right: invalid (bahar chala gaya)  
         * Left-left-up: 4 (row 1, col 0)
         * Left-left-down: invalid (bahar chala gaya)
         * Right-right-up: 6 (row 1, col 2)
         * Right-right-down: invalid (bahar chala gaya)
         * Down-down-left: invalid (bahar chala gaya)
         * Down-down-right: invalid (bahar chala gaya)
       Isliye 0 se sirf {4, 6} ja sakte hain
    */
    vector<vector<int>> moves = {
        {4, 6},    // 0 se: 4 aur 6 par ja sakte hain
        {6, 8},    // 1 se: 6 aur 8 par ja sakte hain  
        {7, 9},    // 2 se: 7 aur 9 par ja sakte hain
        {4, 8},    // 3 se: 4 aur 8 par ja sakte hain
        {0, 3, 9}, // 4 se: 0, 3 aur 9 par ja sakte hain
        {},        // 5 se: koi valid move nahi hai (empty vector)
        {0, 1, 7}, // 6 se: 0, 1 aur 7 par ja sakte hain
        {2, 6},    // 7 se: 2 aur 6 par ja sakte hain
        {1, 3},    // 8 se: 1 aur 3 par ja sakte hain
        {2, 4}     // 9 se: 2 aur 4 par ja sakte hain
    };
    
    /*
    ==========================================
    METHOD 1: PURE RECURSION (Slow but Clear)
    ==========================================
    */
    long long count_ways_solveRE(int digit, int len) {
        /*
        Function ka matlab:
        - digit: current position on keypad (0-9)
        - len: kitne aur digits chahiye total mein
        - Return: kitne ways mein len length ka number bana sakte hain
        */
        
        // Line 1: Base case - agar sirf 1 digit chahiye
        if (len == 1)
            return 1; // Current digit ko rakh dete hain, bas 1 hi way hai
        
        // Line 2: Total ways count karne ke liye variable
        long long total = 0;
        
        // Line 3-5: Current digit se jo bhi moves possible hain, unhe try karo
        for (int next : moves[digit]) {
            /*
            Example: digit=4, len=3 hai
            moves[4] = {0, 3, 9}
            
            Matlab:
            - next=0 ke liye: count_ways_solveRE(0, 2) call karenge
            - next=3 ke liye: count_ways_solveRE(3, 2) call karenge  
            - next=9 ke liye: count_ways_solveRE(9, 2) call karenge
            
            Sabko add kar denge total mein
            */
            total = (total + count_ways_solveRE(next, len - 1)) % MOD;
        }
        return total;
    }
    
    /*
    ===============================================
    METHOD 2: DYNAMIC PROGRAMMING (Fast & Optimal)
    ===============================================
    */
    long long count_ways_solveME(int digit, int len, vector<vector<long long>>& dp) {
        /*
        Function same hai recursion wale ki tarah, bas ek difference:
        - dp table pass kar rahe hain jo already calculated values store karega
        - dp[digit][len] = digit se start karke len length ka number banane ke ways
        */
        
        // Line 1: Base case (same as recursive)
        if (len == 1) return 1;
        
        // Line 2: Check karo ki pehle calculate kiya hai ya nahi
        if (dp[digit][len] != -1) {
            /*
            Agar dp[digit][len] != -1 hai matlab already calculated hai
            To dobara calculate karne ki zarurat nahi, direct return kar do
            
            Example: dp[4][3] = 10 (suppose)
            Agar dubara count_ways_solveME(4, 3, dp) call aaye
            To direct 10 return kar denge, calculation nahi karenge
            */
            return dp[digit][len];
        }
        
        // Line 3: Calculation same recursive wali
        long long total = 0;
        for (int next : moves[digit]) {
            total = (total + count_ways_solveME(next, len - 1, dp)) % MOD;
        }
        
        // Line 4: IMPORTANT - Result ko dp table mein store karo
        return dp[digit][len] = total;
        /*
        Ye line 2 kaam kar rahi hai:
        1. dp[digit][len] = total (store kar diya future ke liye)
        2. return total (current call ke liye return kar diya)
        */
    }
    
    /*
    ===============================
    MAIN FUNCTION - SABSE IMPORTANT
    ===============================
    */
    int knightDialer(int n) {
        /*
        n = kitne digits chahiye phone number mein
        Return = total number of distinct phone numbers possible
        */
        
        // Line 1: Final answer store karne ke liye
        long long ans = 0;
        
        // Line 2: DP table create karo
        vector<vector<long long>> dp(10, vector<long long>(n + 1, -1));
        /*
        dp table explain:
        - 10 rows (digits 0-9 ke liye)
        - n+1 columns (length 1 to n ke liye, 0 index use nahi karenge)
        - Initially sab -1 (means not calculated)
        
        Example: n=3 hai to dp table:
        dp[0][1] dp[0][2] dp[0][3]  <- digit 0 se length 1,2,3 ke ways
        dp[1][1] dp[1][2] dp[1][3]  <- digit 1 se length 1,2,3 ke ways
        ...
        dp[9][1] dp[9][2] dp[9][3]  <- digit 9 se length 1,2,3 ke ways
        */
        
        // Line 3-6: Har digit se start karke try karo
        for (int digit = 0; digit <= 9; digit++) {
            /*
            Ye loop kyun?
            Kyunki phone number kisi bhi digit se start ho sakta hai!
            
            Example: n=2 hai
            - 0 se start: 04, 06 (2 ways)
            - 1 se start: 16, 18 (2 ways)
            - 2 se start: 27, 29 (2 ways)
            - ...
            - Sab add kar denge final answer mein
            */
            ans = (ans + count_ways_solveME(digit, n, dp)) % MOD;
        }
        
        // Line 7: Final answer return karo
        return ans;
    }
};

/*
==================================
STEP BY STEP EXECUTION EXAMPLE
==================================

Suppose n = 2 hai, let's trace:

1. knightDialer(2) call hui

2. dp table banaya:
   dp[0][0] dp[0][1] dp[0][2]
   dp[1][0] dp[1][1] dp[1][2]
   ...
   Initially sab -1

3. digit = 0 ke liye call: count_ways_solveME(0, 2, dp)
   - len != 1, so base case nahi
   - dp[0][2] = -1, so not calculated
   - moves[0] = {4, 6}
   - total = count_ways_solveME(4, 1, dp) + count_ways_solveME(6, 1, dp)
   - count_ways_solveME(4, 1, dp) = 1 (base case)
   - count_ways_solveME(6, 1, dp) = 1 (base case)  
   - total = 1 + 1 = 2
   - dp[0][2] = 2, return 2

4. digit = 1 ke liye call: count_ways_solveME(1, 2, dp)
   - Similar calculation, moves[1] = {6, 8}
   - total = 1 + 1 = 2
   - dp[1][2] = 2, return 2

5. Aise hi saare digits 0-9 ke liye
   Final ans = sum of all ways

Time Complexity: O(n * 10) = O(n)
Space Complexity: O(n * 10) = O(n)

WHY DP BETTER THAN PURE RECURSION?
- Pure recursion mein same (digit, len) combinations baar baar calculate hote hain
- DP mein ek baar calculate karke store kar dete hain
- Example: (4, 1) combination multiple times aayega, but DP mein sirf ek baar calculate hoga
*/