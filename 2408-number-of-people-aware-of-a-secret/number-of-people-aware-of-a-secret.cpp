// class Solution {
// public:
//     int MOD = 1e9 + 7;
//     vector<int> dp;   

//     // This returns number of people who first learn the secret on "day"
//     int solveME(int day, int delay, int forget) {
//         if (day == 1) return 1;
//         if (day <= 0) return 0;

//         if (dp[day] != -1) return dp[day];

//         long long ans = 0;
//         // people who can share today are those who learned it in
//         // [day - forget + 1, day - delay]
//         for (int prev = day - forget + 1; prev <= day - delay; prev++) {
//             if (prev > 0) {
//                 ans = (ans + solveME(prev, delay, forget)) % MOD;
//             }
//         }
//         return dp[day] = ans;
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         dp.assign(n + 1, -1);   
//         long long total = 0;

//         // only count people who haven't forgotten by day n
//         for (int day = n - forget + 1; day <= n; day++) {
//             if (day > 0) {
//                 total = (total + solveME(day, delay, forget)) % MOD;
//             }
//         }
//         return total;
//     }
// };



class Solution {
public:
    int MOD = 1e9 + 7;  
    vector<int> dp;  
    
    // MAIN FUNCTION: Ye return karta hai ki "day" pe kitne log ne PEHLI BAAR secret sikha
    // Matlab wo log jo exactly us din secret discover kiye, pehle se nahi jaante the
    int solveME(int day, int delay, int forget) {
        // Base Case 1: Day 1 pe sirf 1 person ne secret discover kiya
        if (day == 1) return 1;
        
        // Base Case 2: Invalid day (0 ya negative)
        if (day <= 0) return 0;
        
        // Agar already calculate kiya hai toh cache se return karo
        if (dp[day] != -1) return dp[day];
        
        long long ans = 0;
        
        // CRITICAL LOGIC: Kon se log aaj (day pe) secret share kar sakte hain?
        // Answer: Jo log ne secret sikha tha [day-forget+1] se [day-delay] tak
        
        // Kyun? 
        // - Agar kisi ne day-forget pe sikha tha, toh wo day pe forget kar jayega (share nahi kar sakta)
        // - Agar kisi ne day-delay se pehle sikha tha, toh wo abhi tak share kar chuka hai
        // - Agar kisi ne day-delay ke baad sikha tha, toh wo abhi delay period mein hai
        
        for (int prev = day - forget + 1; prev <= day - delay; prev++) {
            if (prev > 0) { // Valid day check
                // prev day pe jo log ne secret sikha tha, wo aaj share karenge
                // Har person jo prev day pe sikha tha, wo aaj 1 naya person ko sikhayega
                ans = (ans + solveME(prev, delay, forget)) % MOD;
            }
        }
        
         return dp[day] = ans;
    }
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // DP array initialize karo (-1 means not calculated)
        dp.assign(n + 1, -1);
        
        long long total = 0;
        
        // FINAL ANSWER: Day n pe kaun log secret jaante hain?
        // Answer: Jo log ne [n-forget+1] se [n] tak secret sikha hai
        
        // Kyun?
        // - Agar kisi ne n-forget se pehle sikha tha, toh wo day n pe forget kar chuka hoga
        // - Agar kisi ne n-forget+1 se n tak sikha hai, toh wo abhi bhi yaad rakhe ga
        
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) { // Valid day check
                // Us day pe jo log ne pehli baar secret sikha, wo abhi bhi jaante hain
                total = (total + solveME(day, delay, forget)) % MOD;
            }
        }
        
        return total;
    }
};

/*
EXAMPLE WALKTHROUGH: n=6, delay=2, forget=4

Day 1: A discovers (1 person discovers)
Day 2: A can't share yet (delay=2, so wait) 
Day 3: A shares with B (1 person discovers - B)
Day 4: A shares with C (1 person discovers - C)
Day 5: A forgets (discovered on day 1, forget=4, so forgets on day 1+4=5)
       B can share now (discovered on day 3, delay=2, so can share from day 3+2=5)
       B shares with D (1 person discovers - D)
Day 6: B shares with E, C shares with F (2 people discover - E,F)

solveME function calls:
- solveME(1) = 1 (base case)
- solveME(2) = 0 (no one can share to make someone discover on day 2)
- solveME(3) = solveME(1) = 1 (person who discovered on day 1 can share)
- solveME(4) = solveME(1) = 1 (person who discovered on day 1 can share)
- solveME(5) = solveME(3) = 1 (person who discovered on day 3 can share)
- solveME(6) = solveME(3) + solveME(4) = 1 + 1 = 2

Final answer: People who know secret on day 6
= solveME(3) + solveME(4) + solveME(5) + solveME(6) 
  (people who discovered from day 6-4+1=3 to day 6)
= 1 + 1 + 1 + 2 = 5 ✓
*/