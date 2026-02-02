using ll = long long;

/*
========================================================
Fenwick Tree (BIT) - Binary Indexed Tree
--------------------------------------------------------
Ye ek tree-based data structure hai jo array operations ko
efficiently handle karta hai.

KYA KARTA HAI?
1. Point Update: Kisi bhi index par value add/subtract karo
2. Prefix Sum: 1 se i tak ka cumulative sum nikalo

KYUN USE KARTE HAIN?
- Normal array me prefix sum: O(n) time
- BIT me dono operations: O(log n) time

BIT KA MAGIC - i & -i:
Ye lowest set bit nikalta hai
Example: i = 6 (binary: 110)
         -i (2's complement): ...11111010
         i & -i = 010 = 2
         
Matlab index 6 responsible hai next 2 positions ke liye

1-INDEXED KYUN?
Kyunki i & -i formula 0 par kaam nahi karta
(0 & -0 = 0, infinite loop ho jayega)
========================================================
*/
class BIT {
public:
    int n;          // total size
    vector<ll> bit; // actual BIT array

    // Constructor: n+1 size ka array banao (index 0 unused rahega)
    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);  // sab 0 se initialize
    }

    /*
    UPDATE OPERATION - O(log n)
    ========================================
    Index 'i' par 'val' add karna hai
    
    But sirf bit[i] update nahi kar sakte!
    Kyunki BIT me har node apne parent nodes ko bhi affect karta hai
    
    Example: i = 5 update karo
    Step 1: bit[5] update (covers [5,5])
    Step 2: bit[6] update (covers [5,6])  -> 5 + (5&-5) = 5+1 = 6
    Step 3: bit[8] update (covers [1,8])  -> 6 + (6&-6) = 6+2 = 8
    Step 4: bit[16] update...
    
    Ye upward propagation hai - parent nodes tak value propagate hoti hai
    */
    void update(int i, ll val) {
        // Jab tak array ke andar hai, update karte jao
        for (; i <= n; i += (i & -i))  // next responsible index par jao
            bit[i] += val;
    }

    /*
    PREFIX SUM QUERY - O(log n)
    ========================================
    Sum nikalo: index 1 se i tak
    
    BIT ka design aisa hai ki:
    - bit[i] stores partial sum (not full prefix)
    - Hume multiple nodes se sum collect karna padta hai
    
    Example: sum(7) chahiye
    Step 1: ans += bit[7]  (covers some range ending at 7)
    Step 2: i = 7 - (7&-7) = 7-1 = 6
            ans += bit[6]  (covers some earlier range)
    Step 3: i = 6 - (6&-6) = 6-2 = 4
            ans += bit[4]  (covers even earlier range)
    Step 4: i = 4 - (4&-4) = 4-4 = 0 -> STOP
    
    Ye backward traversal hai - piche ki taraf sum collect karo
    */
    ll sum(int i) {
        ll ans = 0;
        // Jab tak 0 se zyada hai, sum collect karte jao
        for (; i > 0; i -= (i & -i))  // previous responsible index par jao
            ans += bit[i];
        return ans;
    }
};

/*
========================================================
Coordinate Compression - Bade Numbers Ko Chhota Banao
--------------------------------------------------------
PROBLEM KYA HAI?
- nums[i] can be 1 to 1,000,000,000 (1e9)
- Agar BIT[1e9] size ka banaye to memory overflow!
- But actually unique values kam hote hain

SOLUTION:
Values ko rank de do based on sorted order
[100, 5, 1000, 5, 200, 100]
         ↓
Unique sorted: [5, 100, 200, 1000]
         ↓
Mapping banao:
5    -> 0
100  -> 1  
200  -> 2
1000 -> 3
         ↓
Compressed array: [1, 0, 3, 0, 2, 1]

BENEFIT:
- Original: 1e9 size BIT chahiye
- Compressed: Sirf 4 size BIT chahiye!
- Values ka relative order same rahta hai
- Smaller value → Smaller rank (sorted property preserved)

REAL EXAMPLE:
nums = [1000000, 5, 999999]
After compression: [2, 0, 1]
Ab BIT sirf size 3 ka chahiye instead of 1000000!
========================================================
*/
class Coordinate_Compression {
public:
    // Do mappings maintain karte hain
    unordered_map<int, int> compress; // original value -> compressed rank
    vector<int> rev_map;              // compressed rank -> original value
    
    // Constructor: Array se compression mapping banao
    Coordinate_Compression(const vector<int>& arr) {
        // Step 1: Unique values nikalo aur sort karo
        // set automatically duplicates remove karta hai aur sorted order me store karta hai
        set<int> st(arr.begin(), arr.end());
        
        // Step 2: Har unique value ko ek sequential rank do
        int id = 0;  // rank 0 se start
        for (int x : st) {
            compress[x] = id;      // value x ko rank 'id' assign karo
            rev_map.push_back(x);  // rank 'id' se value 'x' reverse nikalne ke liye
            id++;                   // next rank
        }
        
        /*
        Example execution:
        arr = [100, 5, 100, 200]
        st = {5, 100, 200}  (sorted, unique)
        
        Iteration 1: x=5,   id=0 → compress[5]=0,   rev_map[0]=5
        Iteration 2: x=100, id=1 → compress[100]=1, rev_map[1]=100
        Iteration 3: x=200, id=2 → compress[200]=2, rev_map[2]=200
        */
    }

    // Original array ko compressed ranks me convert karo
    vector<int> get_compressed(const vector<int>& arr) {
        vector<int> res(arr.size());
        for (int i = 0; i < (int)arr.size(); i++)
            res[i] = compress[arr[i]];  // har value ko uski rank se replace karo
        return res;
        
        /*
        Example:
        arr = [100, 5, 100, 200]
        res = [1, 0, 1, 2]
        */
    }

    // Compressed rank se original value wapas nikalo
    int get_original(int idx) {
        return rev_map[idx];
        
        /*
        Example:
        idx = 1 → returns 100
        idx = 0 → returns 5
        */
    }
};

/*
========================================================
getKSmallestSum - K SMALLEST ELEMENTS KA SUM NIKALO
--------------------------------------------------------
YE FUNCTION SABSE IMPORTANT HAI! DHYAN SE SAMJHO!

PROBLEM:
- Window me kuch elements hain (BIT me stored)
- Hume smallest 'need' elements ka sum chahiye
- Normal approach: Sort karke first 'need' elements lo → O(n log n)
- BIT approach with Binary Lifting → O(log M)

BINARY LIFTING CONCEPT:
========================================
BIT ka structure samjho pehle:

BIT array me har index ek RANGE cover karta hai:
bit[1] covers index 1
bit[2] covers indices 1-2  
bit[3] covers index 3
bit[4] covers indices 1-4
bit[5] covers index 5
bit[6] covers indices 5-6
bit[7] covers index 7
bit[8] covers indices 1-8
... and so on

BINARY LIFTING IDEA:
MSB (Most Significant Bit) se start karo
Greedy way me jitna possible ho, left se elements lo
Left side pe smallest elements hain (compression sorted hai!)

DETAILED EXAMPLE:
========================================
Maan lo BIT me ye stored hai (compressed indices):
Index:     0   1   2   3   4   5   6   7
Values:    5  10  15  20  25  30  35  40
cntBIT:    2   1   3   1   2   1   1   1  (kitne elements har index par)
sumBIT:   10  10  45  20  50  30  35  40  (total sum har index par)

Total elements = 2+1+3+1+2+1+1+1 = 12
Hume chahiye: need = 7 smallest

STEP-BY-STEP BINARY LIFTING:
----------------------------

Initial state:
pos = 0 (BIT position, 0-indexed for this explanation)
rem = 7 (remaining elements needed)
ans = 0 (accumulated sum)

Try pw = 128 (2^7): 
  pos+128 = 128 > n? YES → Skip

Try pw = 64 (2^6):
  pos+64 = 64 > n? YES → Skip

Try pw = 32 (2^5):
  pos+32 = 32 > n? YES → Skip

Try pw = 16 (2^4):
  pos+16 = 16 > n? YES → Skip

Try pw = 8 (2^3):
  pos+8 = 8 <= n? YES
  cntBIT.bit[8] kya hai? Maan lo 6
  Is 6 < rem(7)? YES!
  
  Action:
  rem = 7 - 6 = 1
  ans = 0 + sumBIT.bit[8] (maan lo 150)
  pos = 0 + 8 = 8
  
  Matlab: Pehle 6 elements le liye (indices 0-? tak)

Try pw = 4 (2^2):
  pos+4 = 12 <= n? YES
  cntBIT.bit[12] kya hai? Maan lo 2
  Is 2 < rem(1)? NO!
  Skip (kyunki bohot elements ho jayenge)

Try pw = 2 (2^1):
  pos+2 = 10 <= n? YES
  cntBIT.bit[10] kya hai? Maan lo 1
  Is 1 < rem(1)? NO! (equal hai)
  Skip

Try pw = 1 (2^0):
  pos+1 = 9 <= n? YES
  cntBIT.bit[9] kya hai? Maan lo 0
  Is 0 < rem(1)? YES!
  
  Action:
  rem = 1 - 0 = 1
  ans = 150 + 0 = 150
  pos = 8 + 1 = 9

Loop khatam! rem = 1 (abhi bhi chahiye)

Final step:
rem > 0 hai, so:
ans += 1 * cc.get_original(9)  // 1 element, value at compressed index 9

WHY O(log M)?
========================================
- Sirf log2(M) powers try karte hain
- Max 17-20 iterations (2^17 > 100,000)
- Har iteration me constant work
- Total: O(log M)

NORMAL APPROACH VS BINARY LIFTING:
========================================
Normal (multiset):
- Insert: O(log n)
- Delete: O(log n)  
- Find kth smallest: O(k)
- Total per window: O(n log n + k)

Binary Lifting (BIT):
- Insert: O(log M)
- Delete: O(log M)
- Find kth smallest: O(log M)  ← YE ADVANTAGE HAI!
- Total per window: O(log M)

Jab k bada ho, binary lifting bahut fast hai!
========================================================
*/
ll getKSmallestSum(
    int need,                        // kitne smallest elements chahiye (k-1)
    BIT& cntBIT,                     // count BIT: har compressed index pe element count
    BIT& sumBIT,                     // sum BIT: har compressed index pe elements ka total sum
    Coordinate_Compression& cc       // original values wapas nikalne ke liye
) {
    int pos = 0;      // Current position in BIT (0 se start, actual BIT 1-indexed hai)
    ll ans = 0;       // Accumulated sum (final answer)
    int rem = need;   // Remaining elements needed (kitne aur chahiye)

    /*
    BINARY LIFTING LOOP
    ===================
    2^17 = 131,072 which is > 100,000 (max possible array size)
    
    Loop MSB se LSB tak iterate karta hai:
    Iteration 1: pw = 131072 (2^17)
    Iteration 2: pw = 65536  (2^16)
    Iteration 3: pw = 32768  (2^15)
    ...
    Iteration 17: pw = 2     (2^1)
    Iteration 18: pw = 1     (2^0)
    Iteration 19: pw = 0 → Loop ends
    
    Har iteration me pw half ho jata hai (right shift by 1)
    */
    for (int pw = 1 << 17; pw; pw >>= 1) {
        
        /*
        DO CHECKS:
        
        CHECK 1: pos + pw <= cntBIT.n
        --------
        Boundary check - kya jump valid hai?
        Example: pos=5, pw=8, n=10
                 5+8=13 > 10? YES → Invalid, skip
        
        CHECK 2: cntBIT.bit[pos + pw] < rem
        --------
        Kya is position par enough elements nahi hain?
        
        IMPORTANT: cntBIT.bit[pos+pw] me direct count stored hai
        Ye PREFIX sum nahi hai! Direct BIT array access hai
        
        Example visualization:
        pos=0, pw=8, rem=10
        cntBIT.bit[8] = 6  (is position par 6 elements hain)
        Is 6 < 10? YES!
        
        Matlab: Ye 6 elements safely le sakte hain
                Still 4 aur elements chahiye honge (10-6=4)
        
        Agar cntBIT.bit[8] = 12 hota (12 >= 10):
        Skip karte kyunki bohot ho jayenge
        Chhota jump try karenge (pw/2)
        */
        if (pos + pw <= cntBIT.n &&           // Range ke andar hai?
            cntBIT.bit[pos + pw] < rem) {      // Kam elements hain (le sakte hain sab)?
            
            /*
            YE POSITION KE SAARE ELEMENTS LE LO!
            
            Example:
            Before: pos=0, rem=10, ans=0
            cntBIT.bit[8] = 6
            sumBIT.bit[8] = 150 (6 elements ka total)
            
            After:
            rem = 10 - 6 = 4    (4 aur chahiye)
            ans = 0 + 150 = 150 (sum me add kiya)
            pos = 0 + 8 = 8     (position aage badhi)
            
            Ab next iteration me pos=8 se continue karenge
            Aur 4 aur smallest elements dhundhenge
            */
            rem -= cntBIT.bit[pos + pw];       // Elements count reduce karo
            ans += sumBIT.bit[pos + pw];       // Un elements ka sum add karo
            pos += pw;                          // Position update karo
        }
        
        /*
        IF BLOCK EXECUTE NAHI HUA:
        ==========================
        Two reasons possible:
        
        1. pos + pw > n (out of bounds)
           → Chhota jump try karo (pw/2)
        
        2. cntBIT.bit[pos+pw] >= rem (bohot elements hain)
           → Itne saare nahi chahiye, chhota jump try karo
           
        Example:
        rem = 3 chahiye
        cntBIT.bit[pos+8] = 10
        10 >= 3, so skip
        
        Next iteration: pw = 4 try karenge
        Maybe cntBIT.bit[pos+4] = 2 < 3
        Then wo 2 le lenge
        */
    }

    /*
    LOOP KE BAAD REMAINING ELEMENTS
    ================================
    
    Agar rem > 0:
    - Loop me sab nahi mil paye
    - Bache hue elements same compressed index par honge
    
    WHY SAME INDEX?
    - Coordinate compression sorted order me hai
    - Position 'pos' tak ke sab smallest le liye
    - Agle sab same value ke honge (pos+1 index, but 0-indexed)
    
    Example:
    Original values at compressed indices:
    idx 0: [5, 5]        (2 elements, value=5)
    idx 1: [10]          (1 element, value=10)
    idx 2: [15, 15, 15]  (3 elements, value=15)
    
    Suppose loop ke baad:
    pos = 1 (0-indexed in our explanation, but actual BIT 1-indexed)
    rem = 2
    
    Matlab: idx 0 aur 1 ke elements le liye (total 3)
           Abhi 2 aur chahiye
           Wo idx 2 se honge, sab value=15 ke
    
    So: ans += 2 * 15 = 30
    
    NOTE: cc.get_original(pos) gives value at compressed index 'pos'
          In BIT terms, this is actually position pos+1 (1-indexed)
          But getKSmallestSum handles this correctly
    */
    if (rem > 0)
        ans += (ll)rem * cc.get_original(pos);  // remaining elements * their value

    return ans;
}

/*
========================================================
MAIN SOLUTION
========================================================
*/
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        
        /*
        PROBLEM SAMJHO:
        ===============
        - Total k elements select karne hain
        - nums[0] HAMESHA selected hai (given in problem)
        - Baki (k-1) elements nums[1..n-1] se select karo
        - Constraint: selected indices ka (max - min) <= dist
        
        Example:
        nums = [1, 10, 5, 8, 3], k=3, dist=2
        nums[0]=1 selected
        
        Option 1: Select indices {0, 1, 2}
                  Values: {1, 10, 5}
                  Range: 2-0=2 <= dist ✓
                  Sum: 16
        
        Option 2: Select indices {0, 2, 4}  
                  Values: {1, 5, 3}
                  Range: 4-0=4 > dist ✗ (invalid)
        
        Option 3: Select indices {0, 1, 3}
                  Values: {1, 10, 8}
                  Range: 3-0=3 > dist ✗ (invalid)
        
        We need minimum sum among valid options
        */
        
        ll ans = nums[0];  // nums[0] always included

        // Edge case: Sirf 1 element select karna hai
        if (k == 1) return ans;

        /*
        ARRAY TRANSFORMATION:
        ====================
        nums[0] already selected hai, so ignore karo
        Baki elements ke saath kaam karo
        
        Original: [1, 10, 5, 8, 3]  (indices 0,1,2,3,4)
        After:    [10, 5, 8, 3]     (indices 0,1,2,3 in new array)
        
        NEW ARRAY ME INDICES:
        Original nums[1] → arr[0]
        Original nums[2] → arr[1]
        Original nums[3] → arr[2]
        Original nums[4] → arr[3]
        
        Ab agar arr me index i select karte hain,
        to original nums me index (i+1) select ho raha hai
        */
        vector<int> arr(nums.begin() + 1, nums.end());

        /*
        COORDINATE COMPRESSION SETUP:
        ============================
        arr ki unique values ko compress karo
        
        Example:
        arr = [10, 5, 8, 3, 5, 10, 3]
        Unique sorted: [3, 5, 8, 10]
        
        Compression:
        3  → 0
        5  → 1
        8  → 2
        10 → 3
        
        Compressed arr: [3, 1, 2, 0, 1, 3, 0]
        */
        Coordinate_Compression cc(arr);
        vector<int> comp = cc.get_compressed(arr);

        int M = cc.rev_map.size();  // Unique values ki count (BIT ka size)
        
        /*
        DO BIT CHAHIYE:
        ===============
        1. cntBIT: Count track karne ke liye
           - Index i par kitne elements hain?
           - Example: cntBIT[1]=3 → compressed index 1 par 3 elements
        
        2. sumBIT: Sum track karne ke liye  
           - Index i par elements ka total sum?
           - Example: value=5 hai aur 3 elements hain
                     sumBIT[1] = 5+5+5 = 15
        */
        BIT cntBIT(M), sumBIT(M);

        /*
        ========================================================
        WINDOW INITIALIZATION - PEHLA WINDOW SETUP
        --------------------------------------------------------
        
        WINDOW CONCEPT:
        ==============
        Agar hum arr[i] ko minimum index select karte hain,
        to hum arr[i+dist] tak ke indices select kar sakte hain
        
        Window [i, i+dist] me se (k-1) smallest select karenge
        
        PEHLA WINDOW:
        =============
        Start: i=0 (arr ka pehla element)
        End: min(dist, arr.size()-1)
        
        Why min?
        - Agar array chhota hai (dist se kam)
        - To pura array hi window hai
        
        Example 1:
        arr.size() = 10, dist = 3
        window = [0, 3]  (4 elements)
        
        Example 2:
        arr.size() = 2, dist = 5  
        window = [0, 1]  (pura array)
        
        ORIGINAL NUMS ME CORRESPONDING INDICES:
        =======================================
        arr indices [0, dist] → nums indices [1, dist+1]
        
        Constraint check:
        Max index - Min index = dist+1 - 1 = dist ✓
        (nums[0] bhi selected hai, so total range [0, dist+1])
        ========================================================
        */
        int window_start = 0;
        int window_end   = min((int)arr.size() - 1, dist);

        /*
        INITIAL WINDOW KE SAARE ELEMENTS BIT ME ADD KARO:
        ================================================
        
        Example:
        arr = [10, 5, 8, 3]
        comp = [3, 1, 2, 0]  (compressed)
        window = [0, 2]
        
        Loop:
        i=0: arr[0]=10, comp[0]=3
             rank = 3+1 = 4 (BIT 1-indexed)
             cntBIT.update(4, 1)   → cntBIT[4]++
             sumBIT.update(4, 10)  → sumBIT[4] += 10
        
        i=1: arr[1]=5, comp[1]=1
             rank = 1+1 = 2
             cntBIT.update(2, 1)   → cntBIT[2]++
             sumBIT.update(2, 5)   → sumBIT[2] += 5
        
        i=2: arr[2]=8, comp[2]=2  
             rank = 2+1 = 3
             cntBIT.update(3, 1)   → cntBIT[3]++
             sumBIT.update(3, 8)   → sumBIT[3] += 8
        
        Ab BIT me 3 elements hain: values {10, 5, 8}
        */
        for (int i = window_start; i <= window_end; i++) {
            int rank = comp[i] + 1;   // BIT 1-indexed hai, so +1
            cntBIT.update(rank, 1);    // Is rank par 1 element add
            sumBIT.update(rank, arr[i]); // Is rank par arr[i] value add
        }

        /*
        PEHLE WINDOW SE (k-1) SMALLEST NIKALO:
        ======================================
        
        Example continuation:
        k=3, so need k-1=2 smallest
        Window me values: {10, 5, 8}
        Sorted: {5, 8, 10}
        2 smallest: {5, 8}
        Sum: 13
        
        getKSmallestSum efficiently ye calculate karega!
        */
        ll result = getKSmallestSum(k - 1, cntBIT, sumBIT, cc);

        /*
        ========================================================
        SLIDING WINDOW - HAR POSSIBLE WINDOW TRY KARO
        --------------------------------------------------------
        
        CONCEPT:
        ========
        Pehla window try kar liya [0, dist]
        Ab baaki windows try karo:
        [1, dist+1]
        [2, dist+2]
        [3, dist+3]
        ...
        
        Har window se (k-1) smallest nikalo
        Minimum track karo
        
        SLIDING TECHNIQUE:
        ==================
        Window ko ek-ek step aage slide karo:
        
        Before: [window_start .... window_end]
        After:  [window_start+1 .... window_end+1]
        
        Changes:
        - Remove: arr[window_start] (left side se nikal gaya)
        - Add: arr[window_end+1] (right side se aaya)
        
        Example:
        arr = [10, 5, 8, 3, 7, 2]
        
        Window 1: [0,2] = {10,5,8}  → 2 smallest = {5,8} = 13
        Window 2: [1,3] = {5,8,3}   → 2 smallest = {5,3} = 8  ← Better!
        Window 3: [2,4] = {8,3,7}   → 2 smallest = {3,7} = 10
        Window 4: [3,5] = {3,7,2}   → 2 smallest = {3,2} = 5  ← Best!
        
        Final answer = nums[0] + 5
        ========================================================
        */
        while (window_end + 1 < (int)arr.size()) {

            /*
            STEP 1: LEFT ELEMENT REMOVE KARO
            ================================
            
            Outgoing element: arr[window_start]
            
            BIT se remove karne ke liye:
            - Count -1 karo (ek element kam)
            - Sum me se value subtract karo
            
            Example:
            arr[window_start] = 10
            comp[window_start] = 3
            rank = 3+1 = 4
            
            cntBIT.update(4, -1)  → cntBIT[4]--
            sumBIT.update(4, -10) → sumBIT[4] -= 10
            
            Agar same value ke multiple elements the:
            Before: cntBIT[4]=2, sumBIT[4]=20 (two 10s)
            After:  cntBIT[4]=1, sumBIT[4]=10 (one 10)
            */
            cntBIT.update(comp[window_start] + 1, -1);           
            sumBIT.update(comp[window_start] + 1, -arr[window_start]); 
            window_start++;  // Window start aage badha

            /*
            STEP 2: RIGHT ELEMENT ADD KARO
            ===============================
            
            Incoming element: arr[window_end+1]
            
            BIT me add karne ke liye:
            - Count +1 karo (ek element zyada)
            - Sum me value add karo
            
            Example:
            window_end+1 = 3
            arr[3] = 3
            comp[3] = 0
            rank = 0+1 = 1
            
            cntBIT.update(1, 1)   → cntBIT[1]++
            sumBIT.update(1, 3)   → sumBIT[1] += 3
            */
            window_end++;  // Pehle window end badhao
            cntBIT.update(comp[window_end] + 1, 1);              
            sumBIT.update(comp[window_end] + 1, arr[window_end]); 

            /*
            STEP 3: NAYE WINDOW KA (k-1) SMALLEST SUM NIKALO
            ================================================
            
            Ab BIT me updated elements hain
            Binary lifting se efficiently sum nikalo
            Agar current sum previous se chhota, update karo
            
            Example:
            Previous result = 13
            Current window sum = 8
            result = min(13, 8) = 8 ← Update!
            */
            result = min(result, getKSmallestSum(k - 1, cntBIT, sumBIT, cc));
        }

        /*
        FINAL ANSWER:
        =============
        nums[0] (always selected) + best (k-1) elements ka sum
        
        Example:
        nums[0] = 1
        best (k-1) sum = 5
        Final answer = 1 + 5 = 6
        */
        return ans + result;
    }
};

/*
========================================================
COMPLEXITY ANALYSIS - TIME & SPACE
========================================================

TIME COMPLEXITY:
===============

1. Coordinate Compression Setup: O(n log n)
   - Set insertion: O(n log n)
   - Creating mappings: O(M) where M = unique values
   
2. Window Initialization: O(dist * log M)
   - dist+1 elements add karna
   - Har update: O(log M)
   
3. Sliding Window Loop: O(n * log M)
   - n-dist iterations (approximately O(n))
   - Har iteration:
     * 2 removes: 2 * O(log M)
     * 2 adds: 2 * O(log M)
     * 1 getKSmallestSum: O(log M)
     * Total per iteration: O(log M)
   
4. getKSmallestSum: O(log M)
   - Binary lifting: maximum 17-20 iterations
   - Each iteration: O(1) array access
   
TOTAL TIME: O(n log n + n log M) = O(n log n)
(kyunki M <= n)

SPACE COMPLEXITY:
================

1. Coordinate Compression:
   - compress map: O(M)
   - rev_map vector: O(M)
   
2. BIT Arrays:
   - cntBIT: O(M)
   - sumBIT: O(M)
   
3. Temporary Arrays:
   - arr: O(n)
   - comp: O(n)
   
TOTAL SPACE: O(n + M) = O(n)

========================================================
COMPARISON WITH OTHER APPROACHES:
========================================================

APPROACH 1: Multiset (Typical Solution)
----------------------------------------
Time: O(n * k * log n)
- Har window ke liye multiset maintain
- Insert/Delete: O(log n)
- Find kth smallest: O(k) by iterating
- If k is large, very slow!

Space: O(k)
- Multiset me k elements

APPROACH 2: BIT + Binary Lifting (This Solution)
-------------------------------------------------
Time: O(n log n)
- Much faster when k is large
- getKSmallestSum: O(log M) instead of O(k)
- Example: k=1000 → 1000 iterations vs 17 iterations!

Space: O(n)
- BIT arrays need more space

WHEN TO USE WHICH?
==================
- Small k (k < 100): Multiset is simpler
- Large k (k > 100): BIT + Binary Lifting is much faster
- This problem: k can be large, so BIT approach optimal!

========================================================
KEY TAKEAWAYS:
========================================================
1. Coordinate compression: Large values → Small indices
2. Binary Indexed Tree: Fast updates and queries
3. Binary lifting: Find kth smallest in O(log n)
4. Sliding window: Try all valid ranges efficiently

Samjh aa gaya? Implementation bhi samajh aa gayi? 🚀
*/