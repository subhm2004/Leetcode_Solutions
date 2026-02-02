using ll = long long;

/*
========================================================
FENWICK TREE / BINARY INDEXED TREE (BIT)
========================================================
Ye data structure hai jo efficiently:
1. Point update kar sakta hai: O(log n)
2. Prefix sum query kar sakta hai: O(log n)

Use case: Given sorted values, count kitne values ≤ threshold hain
========================================================
*/
class BIT {
public:
    int n;
    vector<ll> bit;

    // Constructor: size n ka BIT banao
    BIT(int n) {
        this->n = n;
        bit.resize(n + 1, 0);  // 1-indexed, so size = n+1
    }

    /*
    ====================================================
    UPDATE: index i pe value x add karo
    ====================================================
    BIT mein index i se start karke uske sabhi "parents"
    ko update karna hota hai.
    
    Parent kaise milta hai?
    i += (i & -i)  →  ye next parent index deta hai
    
    Example: i=4 (binary: 100)
        i & -i = 4
        4 + 4 = 8  →  next parent
    ====================================================
    */
    void update(int i, ll x) {
        for (; i <= n; i += (i & -i))
            bit[i] += x;
    }

    /*
    ====================================================
    SUM: prefix sum [1..i] ka sum return karo
    ====================================================
    BIT se range sum nikalne ke liye:
    Index i se start karke peeche jaate hain (parents)
    
    Previous index kaise milta hai?
    i -= (i & -i)  →  previous parent
    
    Example: i=7 (binary: 111)
        i & -i = 1
        7 - 1 = 6
        6 - 2 = 4
        4 - 4 = 0  →  stop
    ====================================================
    */
    ll sum(int i) {
        ll total = 0;
        for (; i > 0; i -= (i & -i))
            total += bit[i];
        return total;
    }

    /*
    ====================================================
    RANGE_SUM: [l..r] range ka sum
    ====================================================
    Prefix sum property use karo:
    sum[l..r] = sum[1..r] - sum[1..l-1]
    ====================================================
    */
    ll range_Sum(int l, int r) {
        if (l > r)
            return 0;
        return sum(r) - sum(l - 1);
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {

        int n = nums1.size();

        /*
        ========================================================
        PROBLEM TRANSFORMATION
        ========================================================
        Original condition:
            nums1[i] - nums1[j] ≤ nums2[i] - nums2[j] + diff
        
        Rearrange karo:
            nums1[i] - nums2[i] ≤ nums1[j] - nums2[j] + diff
        
        Define: A[i] = nums1[i] - nums2[i]
        
        Then condition becomes:
            A[i] ≤ A[j] + diff
        OR
            A[i] - diff ≤ A[j]
        
        Goal: Count pairs (i,j) where i < j and A[i] ≤ A[j] + diff
        ========================================================
        */

        /*
        ========================================================
        OFFSET & RANGE SETUP
        ========================================================
        A[i] = nums1[i] - nums2[i]
        Range: -10^4 ≤ nums1[i], nums2[i] ≤ 10^4
        
        So: -20000 ≤ A[i] ≤ 20000
        
        limit = A[j] + diff
        Range: -30000 ≤ limit ≤ 30000  (approx)
        
        BIT ke liye positive indices chahiye.
        OFFSET = 30000 use karte hain taaki:
            -30000 → 0
            0      → 30000
            30000  → 60000
        
        MAXV = 60001 (total possible values + 1)
        ========================================================
        */
        const int OFFSET = 30000;
        const int MAXV = 60001;

        BIT bit(MAXV);

        ll ans = 0;

        /*
        ========================================================
        MAIN ALGORITHM
        ========================================================
        Process elements LEFT TO RIGHT (j = 0 to n-1)
        
        For each j:
        1. Calculate A[j] = nums1[j] - nums2[j]
        2. Calculate limit = A[j] + diff
        3. Query: Kitne i < j exist karte hain jahan A[i] ≤ limit?
        4. Update: A[j] ko BIT mein add karo (future queries ke liye)
        
        WHY THIS WORKS:
        - Jab j process kar rahe ho, tabtak sab i < j already
          BIT mein add ho chuke hain
        - Query: "count values ≤ limit" gives count of valid i's
        ========================================================
        */

        for (int j = 0; j < n; j++) {

            /*
            ================================================
            STEP 1: Calculate A[j] and limit
            ================================================
            A[j] = nums1[j] - nums2[j]
            
            Condition: A[i] ≤ A[j] + diff
            Rearrange: A[i] ≤ limit, where limit = A[j] + diff
            ================================================
            */
            int A = nums1[j] - nums2[j];
            int limit = A + diff;

            /*
            ================================================
            STEP 2: Convert limit to BIT index
            ================================================
            limit range: [-30000, 30000]
            BIT index: [1, 60001]
            
            Formula: index = limit + OFFSET + 1
            
            Why +1?
            - BIT is 1-indexed
            - sum(qidx) returns count of values in [1..qidx]
            - We want count of values ≤ limit
            
            Example:
            limit = 5
            qidx = 5 + 30000 + 1 = 30006
            sum(30006) = count of all A[i] ≤ 5 added so far
            ================================================
            */
            int qidx = limit + OFFSET + 1;

            /*
            ================================================
            BOUNDARY CHECKS
            ================================================
            Ensure qidx stays within BIT bounds [1, MAXV]
            
            If limit is very negative → qidx < 1 → clamp to 1
            If limit is very positive → qidx > MAXV → clamp to MAXV
            ================================================
            */
            if (qidx < 1)
                qidx = 1;
            if (qidx > MAXV)
                qidx = MAXV;

            /*
            ================================================
            STEP 3: QUERY BIT
            ================================================
            sum(qidx) returns:
            "Kitne elements abtak add kiye jo ≤ limit hain"
            
            Since hum j=0 se process kar rahe hain:
            - All these elements have index i < j
            - All satisfy A[i] ≤ limit = A[j] + diff
            
            → This is exactly the count of valid pairs (i,j)!
            ================================================
            */
            ans += bit.sum(qidx);

            /*
            ================================================
            STEP 4: UPDATE BIT with current A[j]
            ================================================
            A[j] ko BIT mein add karo so that future j's
            can count this element.
            
            Convert A to BIT index:
            idx = A + OFFSET + 1
            
            Example:
            A = -5
            idx = -5 + 30000 + 1 = 29996
            
            bit.update(29996, 1) means:
            "Value -5 ko count mein add karo"
            ================================================
            */
            int idx = A + OFFSET + 1;
            bit.update(idx, 1);
        }

        return ans;
    }
};

/*
========================================================
DRY RUN: Example 1
========================================================
Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1

Compute A[i] = nums1[i] - nums2[i]:
    A[0] = 3 - 2 = 1
    A[1] = 2 - 2 = 0
    A[2] = 5 - 1 = 4

Condition: A[i] ≤ A[j] + diff

Check all pairs:
1. (i=0, j=1): A[0]=1 ≤ A[1]+1=0+1=1 ✓ (1 ≤ 1)
2. (i=0, j=2): A[0]=1 ≤ A[2]+1=4+1=5 ✓ (1 ≤ 5)
3. (i=1, j=2): A[1]=0 ≤ A[2]+1=4+1=5 ✓ (0 ≤ 5)

Expected: 3 pairs

--- Algorithm Trace ---

j=0: A=1, limit=1+1=2
    qidx = 2 + 30000 + 1 = 30003
    ans += bit.sum(30003) = 0  (BIT empty)
    Add A=1 at idx = 1 + 30000 + 1 = 30002
    BIT: {30002: 1}

j=1: A=0, limit=0+1=1
    qidx = 1 + 30000 + 1 = 30002
    ans += bit.sum(30002)
         = count of values ≤ 1
         = 1  (value 1 exists at idx 30002)
    ans = 1
    Add A=0 at idx = 0 + 30000 + 1 = 30001
    BIT: {30001: 1, 30002: 1}

j=2: A=4, limit=4+1=5
    qidx = 5 + 30000 + 1 = 30006
    ans += bit.sum(30006)
         = count of values ≤ 5
         = 2  (values 0 and 1 both ≤ 5)
    ans = 1 + 2 = 3
    Add A=4 at idx = 4 + 30000 + 1 = 30005

Output: 3 ✓
========================================================
*/

/*
========================================================
KEY INSIGHTS
========================================================

1. TRANSFORMATION:
   nums1[i] - nums1[j] ≤ nums2[i] - nums2[j] + diff
   →  A[i] ≤ A[j] + diff
   where A[k] = nums1[k] - nums2[k]

2. INVERSION COUNT VARIANT:
   For each j, count how many i < j satisfy A[i] ≤ A[j] + diff
   This is like counting inversions but with a threshold

3. BIT USAGE:
   - Process j from left to right
   - Query: count elements ≤ threshold
   - Update: add current element
   - Time: O(n log MAXV) = O(n log 60000) ≈ O(n * 16)

4. COORDINATE COMPRESSION NOT NEEDED:
   Range already bounded: [-30000, 30000]
   Direct mapping to BIT indices works fine

5. OFFSET TRICK:
   Convert negative values to positive BIT indices
   -30000 → 1, 0 → 30001, 30000 → 60001
========================================================
*/