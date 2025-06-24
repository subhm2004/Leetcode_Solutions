//  https://www.youtube.com/watch?v=1lLmo2aC29o

// PROBLEM STATEMENT:
// - Start at stair 1
// - Goal: Reach stair K
// - Two types of moves:
//   1. Go back 1 step (only if you just came from a jump, can_Go_Back = true)
//   2. Jump forward 2^jump steps (jump starts from 0, increments each time)
// - Find total number of ways to reach stair K

typedef unsigned long long ull;

class Solution {
public:
    // ===== RECURSIVE SOLUTION (WITHOUT MEMOIZATION) =====
    ull solveRE(ull i, ull jump, bool can_Go_Back, ull K, vector<long long>& power) {
        
        // ===== BASE CASE: OUT OF BOUNDS =====
        // Agar current position K+2 se zyada ho gaya, toh invalid path hai
        // Why K+2? Kyunki K+1 se hum 1 step back kar ke K pe aa sakte hain
        // Lekin K+2 se back jane ke baad K+1 pe aate hain, jo K tak pahunchne ke liye
        // aur steps chahiye jinse overcomplicate ho jaega
        if (i > K + 2)
            return 0;
        
        // Total ways accumulator
        ull ans_ways = 0;
        
        // ===== SUCCESS CASE: TARGET REACHED =====
        // Agar hum exactly K-th stair pe pahunch gaye hain
        if (i == K) {
            ans_ways++;  // Ye ek valid way hai
            // Note: Hum yahan ruk sakte hain YA aur moves bhi try kar sakte hain
            // Kyunki problem multiple ways count karne ke liye hai
        }
        
        // ===== MOVE 1: GO BACK (CONDITIONAL) =====
        // Sirf tab back jaa sakte hain jab can_Go_Back = true
        // Ye true hota hai sirf jump ke baad
        if (can_Go_Back == true) {
            // 1 step back jao
            // can_Go_Back ko false kar do kyunki consecutive back moves allowed nahi
            ans_ways += solveRE(i - 1, jump, false, K, power);
        }
        
        // ===== MOVE 2: JUMP FORWARD (ALWAYS POSSIBLE) =====
        // Hamesha jump kar sakte hain 2^jump distance
        // Jump ke baad can_Go_Back = true ho jaata hai
        // jump counter increment ho jaata hai next jump ke liye
        ans_ways += solveRE(i + power[jump], jump + 1, true, K, power);
        
        return ans_ways;  // Total ways return karo
    }
    
    ull solveME(ull i, ull jump, bool can_Go_Back, ull K, vector<long long>& power, 
                unordered_map<string, ull>& dp) {
        
        if (i > K + 2)
            return 0;
        

        auto key = to_string(i) + "_" + to_string(jump) + "_" + to_string(can_Go_Back);
        
        if (dp.find(key) != dp.end())
            return dp[key];   
        
        ull ans_ways = 0;
        
        if (i == K) {
            ans_ways++;
        }
        
        if (can_Go_Back == true) {
            ans_ways += solveME(i - 1, jump, false, K, power, dp);
        }
        
        ans_ways += solveME(i + power[jump], jump + 1, true, K, power, dp);
        
        return dp[key] = ans_ways;
    }
    
    ull waysToReachStair(ull k) {
        
        unordered_map<string, ull> dp;
        
        // power[i] = 2^i for i = 0 to 63
        vector<long long> power(64);
        
        for (ull i = 0; i < 64; ++i) {
            // Efficient way to compute 2^i using bit shifting
            power[i] = (1LL << i);  // 2^i
            
            // Alternative: power[i] = pow(2, i); (but slower)
        }
        
        return solveME(1, 0, true, k, power, dp);
    }
};

/*
===== DETAILED EXAMPLE WALKTHROUGH =====

Let's trace through waysToReachStair(4):

INITIAL STATE:
- i = 1 (starting position)
- jump = 0 (first jump will be 2^0 = 1)
- can_Go_Back = true
- K = 4 (target)
- power = [1, 2, 4, 8, 16, 32, ...]

CALL TREE VISUALIZATION:

solveRE(1, 0, true, 4, power)
├── i ≠ 4, so ans_ways = 0
├── can_Go_Back = true, so try going back:
│   └── solveRE(0, 0, false, 4, power)
│       ├── i ≠ 4, so ans_ways = 0
│       ├── can_Go_Back = false, so no back move
│       └── Jump forward: solveRE(0 + power[0], 1, true, 4, power)
│           └── solveRE(1, 1, true, 4, power) ... [recursive calls continue]
└── Jump forward: solveRE(1 + power[0], 1, true, 4, power)
    └── solveRE(2, 1, true, 4, power)
        ├── i ≠ 4, so ans_ways = 0
        ├── can_Go_Back = true, so try going back:
        │   └── solveRE(1, 1, false, 4, power)
        │       ├── i ≠ 4, so ans_ways = 0
        │       ├── can_Go_Back = false, so no back move
        │       └── Jump forward: solveRE(1 + power[1], 2, true, 4, power)
        │           └── solveRE(3, 2, true, 4, power)
        │               ├── i ≠ 4, so ans_ways = 0
        │               ├── can_Go_Back = true, so try going back:
        │               │   └── solveRE(2, 2, false, 4, power)
        │               │       └── ... [continues recursively]
        │               └── Jump forward: solveRE(3 + power[2], 3, true, 4, power)
        │                   └── solveRE(7, 3, true, 4, power)
        │                       └── i > K+2, return 0
        └── Jump forward: solveRE(2 + power[1], 2, true, 4, power)
            └── solveRE(4, 2, true, 4, power)
                ├── i == 4, so ans_ways = 1 ✓
                ├── can_Go_Back = true, so try going back:
                │   └── solveRE(3, 2, false, 4, power)
                │       └── ... [continues recursively]
                └── Jump forward: solveRE(4 + power[2], 3, true, 4, power)
                    └── solveRE(8, 3, true, 4, power)
                        └── i > K+2, return 0

PATH ANALYSIS FOR K = 4:

VALID PATHS TO REACH STAIR 4:

Path 1: 1 → 2 → 4
- Start at 1
- Jump 2^0 = 1 step: 1 + 1 = 2
- Jump 2^1 = 2 steps: 2 + 2 = 4 ✓

Path 2: 1 → 2 → 1 → 3 → 4
- Start at 1
- Jump 2^0 = 1 step: 1 + 1 = 2
- Go back 1 step: 2 - 1 = 1
- Jump 2^1 = 2 steps: 1 + 2 = 3
- Jump 2^2 = 4 steps: 3 + 4 = 7 (overshoots)
- Actually, let me correct this...

Let me trace more carefully:

Path 1: 1 → 2 → 4
- solveRE(1, 0, true, 4, power)
- Jump: 1 + 2^0 = 2, next call: solveRE(2, 1, true, 4, power)
- Jump: 2 + 2^1 = 4, next call: solveRE(4, 2, true, 4, power)
- i == 4, count this path! ✓

Path 2: 1 → 2 → 1 → 3 → 4
- solveRE(1, 0, true, 4, power)
- Jump: 1 + 2^0 = 2, next call: solveRE(2, 1, true, 4, power)
- Go back: 2 - 1 = 1, next call: solveRE(1, 1, false, 4, power)
- Jump: 1 + 2^1 = 3, next call: solveRE(3, 2, true, 4, power)
- Go back: 3 - 1 = 2, next call: solveRE(2, 2, false, 4, power)
- Jump: 2 + 2^2 = 6, next call: solveRE(6, 3, true, 4, power)
- i > K+2, return 0

Wait, let me check if there's a path through 3:
- From solveRE(3, 2, true, 4, power)
- Jump: 3 + 2^2 = 7 (too far)
- Go back: 3 - 1 = 2, then solveRE(2, 2, false, 4, power)
- Jump: 2 + 2^2 = 6 (too far)

Actually, let me recalculate systematically...

SYSTEMATIC TRACE FOR K = 4:

Starting: solveRE(1, 0, true, 4, power)

Branch 1: Go back to 0
- solveRE(0, 0, false, 4, power)
- Only option: Jump 0 + 2^0 = 1
- solveRE(1, 1, true, 4, power)
- This creates a cycle, but let's continue...

Branch 2: Jump forward to 2
- solveRE(2, 1, true, 4, power)
- Sub-branch 2.1: Go back to 1
  - solveRE(1, 1, false, 4, power)
  - Only option: Jump 1 + 2^1 = 3
  - solveRE(3, 2, true, 4, power)
  - This will either go to 2 (back) or 7 (jump), neither directly helps
- Sub-branch 2.2: Jump forward to 4
  - solveRE(4, 2, true, 4, power)
  - i == 4, so ans_ways = 1 ✓
  - This is one valid path!

So we have at least 1 way: 1 → 2 → 4

The algorithm will find all possible paths and count them.

===== MEMOIZATION BENEFIT =====

Without memoization: O(2^n) - exponential time
With memoization: O(number of unique states)

State space: (position, jump_count, can_go_back)
- position: limited by K+2 bound
- jump_count: limited by log(K) since 2^jump grows exponentially
- can_go_back: boolean (2 values)

Total states: O(K * log(K) * 2) = O(K * log(K))

===== KEY ALGORITHMIC INSIGHTS =====

1. RECURSIVE THINKING: Break problem into smaller subproblems
2. STATE MANAGEMENT: Track position, jump count, and back permission
3. MEMOIZATION: Avoid recomputing same states
4. BOUNDARY CONDITIONS: Prevent infinite exploration with K+2 limit
5. CONSTRAINT MODELING: can_Go_Back flag models consecutive back restriction

===== COMPLEXITY ANALYSIS =====

TIME COMPLEXITY:
- Without memoization: O(2^n) where n depends on K
- With memoization: O(K * log(K)) states, each computed once

SPACE COMPLEXITY:
- Recursion depth: O(log(K)) maximum
- Memoization table: O(K * log(K))
- Power array: O(64) = O(1)
- Total: O(K * log(K))

===== OPTIMIZATION NOTES =====

1. PRECOMPUTED POWERS: Avoid repeated pow() calls
2. BIT SHIFTING: (1LL << i) faster than pow(2, i)
3. STRING KEYS: Could be optimized with custom hash function
4. EARLY TERMINATION: i > K+2 prevents excessive exploration
*/