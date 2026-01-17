class Solution {
public:
    // dp[pos][tight][started]
    long long dp[20][2][2];
    string s;
    int limit;
    
    long long solve(int pos, bool tight, bool started) {
        // Base case: reached end
        if (pos == s.size()) {
            // Count all numbers, even if started=false (prefix can be 0)
            return 1;
        }
        
        // Check memoization
        if (dp[pos][tight][started] != -1) {
            return dp[pos][tight][started];
        }
        
        long long result = 0;
        int upperLimit = tight ? (s[pos] - '0') : 9;
        
        // Try digits from 0 to min(upperLimit, limit)
        for (int digit = 0; digit <= min(upperLimit, limit); digit++) {
            bool newStarted = started || (digit > 0);
            bool newTight = tight && (digit == upperLimit);
            
            result += solve(pos + 1, newTight, newStarted);
        }
        
        // Store in dp (for both tight and non-tight)
        return dp[pos][tight][started] = result;
    }
    
    long long countPrefix(long long num) {
        if (num < 0) return 0;
        
        s = to_string(num);
        memset(dp, -1, sizeof(dp));
        return solve(0, true, false);
    }
    
    long long numberOfPowerfulInt(long long start, long long finish, int lim, string suffix) {
        limit = lim;
        
        int k = suffix.size();
        long long S = stoll(suffix);  // suffix ka numeric value
        
        // Check if suffix itself is in valid range
        // If S > finish, no valid numbers possible
        if (S > finish) return 0;
        
        // Calculate 10^k
        long long pow10 = 1;
        for (int i = 0; i < k; i++) {
            pow10 *= 10;
        }
        
        // Transform problem:
        // Original: start <= prefix*10^k + S <= finish
        // Rearrange: (start-S)/10^k <= prefix <= (finish-S)/10^k
        
        // Lower bound: L = ceil((start - S) / pow10)
        long long L = (start - S + pow10 - 1) / pow10;
        
        // Upper bound: R = floor((finish - S) / pow10)
        long long R = (finish - S) / pow10;
        
        // If no valid prefix range exists
        if (R < L) return 0;
        
        // Additional check: L should be >= 0
        // If L < 0, it means even with prefix=0, number is < start
        // But we need to ensure prefix*10^k + S >= start
        if (L < 0) L = 0;
        
        // Count prefixes in [L, R] where each digit <= limit
        return countPrefix(R) - countPrefix(L - 1);
    }
};


/*
═══════════════════════════════════════════════════════════════════════════
                    DETAILED EXPLANATION
═══════════════════════════════════════════════════════════════════════════

PROBLEM TRANSFORMATION:

Original: Count numbers N where:
  - start ≤ N ≤ finish
  - N ends with suffix s
  - Each digit of N ≤ limit

Transform to: Count prefixes P where:
  - L ≤ P ≤ R  
  - Each digit of P ≤ limit
  
Where: N = P × 10^k + S
       k = length of suffix
       S = numeric value of suffix

═══════════════════════════════════════════════════════════════════════════

MATHEMATICAL DERIVATION:

Step 1: Express constraint
  start ≤ P × 10^k + S ≤ finish

Step 2: Isolate prefix P
  start - S ≤ P × 10^k ≤ finish - S
  
Step 3: Divide by 10^k
  (start - S) / 10^k ≤ P ≤ (finish - S) / 10^k

Step 4: Handle integer bounds
  L = ⌈(start - S) / 10^k⌉  (ceiling)
  R = ⌊(finish - S) / 10^k⌋  (floor)

Step 5: Ceiling trick in C++
  ceil(a/b) = (a + b - 1) / b  (for positive b)
  
  L = (start - S + pow10 - 1) / pow10

═══════════════════════════════════════════════════════════════════════════

EXAMPLE 1: start=1, finish=6000, limit=4, s="124"

Given:
  S = 124
  k = 3
  pow10 = 1000

Check: S > finish? 124 > 6000? No ✓ (continue)

Calculate L:
  L = (1 - 124 + 1000 - 1) / 1000
    = 876 / 1000
    = 0

Calculate R:
  R = (6000 - 124) / 1000
    = 5876 / 1000
    = 5

Check: L < 0? No ✓
Check: R < L? 5 < 0? No ✓

Prefix range: [0, 5]

Check which prefixes have all digits ≤ 4:
  0 → ✓ (0 ≤ 4)
  1 → ✓ (1 ≤ 4)
  2 → ✓ (2 ≤ 4)
  3 → ✓ (3 ≤ 4)
  4 → ✓ (4 ≤ 4)
  5 → ✗ (5 > 4)

Valid prefixes: 5
Answer: 5 ✓

Corresponding numbers:
  0 × 1000 + 124 = 124
  1 × 1000 + 124 = 1124
  2 × 1000 + 124 = 2124
  3 × 1000 + 124 = 3124
  4 × 1000 + 124 = 4124

═══════════════════════════════════════════════════════════════════════════

EXAMPLE 2: start=15, finish=215, limit=6, s="10"

Given:
  S = 10
  k = 2
  pow10 = 100

Check: S > finish? 10 > 215? No ✓ (continue)

Calculate L:
  L = (15 - 10 + 100 - 1) / 100
    = 104 / 100
    = 1

Calculate R:
  R = (215 - 10) / 100
    = 205 / 100
    = 2

Check: L < 0? No ✓
Check: R < L? 2 < 1? No ✓

Prefix range: [1, 2]

Check which prefixes have all digits ≤ 6:
  1 → ✓ (1 ≤ 6)
  2 → ✓ (2 ≤ 6)

Valid prefixes: 2
Answer: 2 ✓

Corresponding numbers:
  1 × 100 + 10 = 110
  2 × 100 + 10 = 210

═══════════════════════════════════════════════════════════════════════════

EXAMPLE 3: start=1000, finish=2000, limit=4, s="3000"

Given:
  S = 3000
  k = 4
  pow10 = 10000

Check: S > finish? 3000 > 2000? Yes ✓
Return 0 immediately ✓

Answer: 0 ✓

Explanation:
  Smallest possible number = 0 × 10000 + 3000 = 3000
  But 3000 > finish (2000)
  So NO valid numbers exist

═══════════════════════════════════════════════════════════════════════════

EXAMPLE 2: start=15, finish=215, limit=6, s="10"

Given:
  S = 10
  k = 2
  pow10 = 100

Calculate L:
  L = (15 - 10 + 100 - 1) / 100
    = 104 / 100
    = 1

Calculate R:
  R = (215 - 10) / 100
    = 205 / 100
    = 2

Prefix range: [1, 2]

Check which prefixes have all digits ≤ 6:
  1 → ✓ (1 ≤ 6)
  2 → ✓ (2 ≤ 6)

Valid prefixes: 2
Answer: 2 ✓

Corresponding numbers:
  1 × 100 + 10 = 110
  2 × 100 + 10 = 210

═══════════════════════════════════════════════════════════════════════════

WHY THIS TRANSFORMATION WORKS:

1. Suffix is FIXED:
   - We don't need to check suffix digits in DP
   - Problem statement guarantees suffix digits ≤ limit
   
2. Prefix is VARIABLE:
   - We only need to count valid prefixes
   - Use standard digit DP with digit constraint
   
3. Range Conversion:
   - Original range [start, finish] for full numbers
   - Becomes range [L, R] for prefixes
   - Mathematical transformation is exact
   
4. Digit Constraint:
   - Apply to prefix digits only
   - Suffix already satisfies constraint (given)

═══════════════════════════════════════════════════════════════════════════

DIGIT DP STATES:

dp[pos][tight][started]

pos: current position in prefix
tight: are we bounded by upper limit
started: have we placed a non-zero digit (for leading zeros)

Transitions:
- Try digit d from 0 to min(upperLimit, limit)
- Update tight: newTight = tight && (d == upperLimit)
- Update started: newStarted = started || (d > 0)

Base case:
- pos == prefixLength: return 1 if started, else 0

═══════════════════════════════════════════════════════════════════════════

TIME COMPLEXITY:

- Calculate L, R: O(k) where k = suffix length
- Digit DP: O(20 × 2 × 2 × limit) = O(80 × limit) per query
- Two queries (for R and L-1): O(160 × limit)
- Total: O(k + 160 × limit) ≈ O(1600) for limit=9

SPACE COMPLEXITY:

- DP array: O(20 × 2 × 2) = O(80)
- Total: O(80)

═══════════════════════════════════════════════════════════════════════════
*/