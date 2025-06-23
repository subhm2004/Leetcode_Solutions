class SegmentTree {
private:
    int n; // Array ka size
    vector<unordered_map<int, int>> segTree; // Har node me value->frequency map store karte hain
    
    // Segment tree ko recursively build karne ka function
    void build(const vector<int>& arr, int node, int l, int r) {
        // Base case: agar ye leaf node hai (sirf ek element)
        if (l == r) {
            segTree[node][arr[l]] = 1;  // Us single element ka frequency 1 set kar do
            return;
        }
        
        // Recursive case: internal node hai, bachon ko build karo
        int mid = (l + r) / 2;
        build(arr, 2 * node + 1, l, mid);        // Left child build karo
        build(arr, 2 * node + 2, mid + 1, r);   // Right child build karo
        
        // Ab dono bachon ke frequency maps ko merge kar do current node me
        // Left child ke saare elements le kar current node me add kar do
        for (const auto& [val, freq] : segTree[2 * node + 1])
            segTree[node][val] += freq;
        
        // Right child ke saare elements le kar current node me add kar do
        for (const auto& [val, freq] : segTree[2 * node + 2])
            segTree[node][val] += freq;
    }
    
    // Kisi specific value ka frequency nikalne ka function range [ql, qr] me
    int query(int node, int l, int r, int ql, int qr, int value) {
        // Agar query range aur current node ka range overlap nahi kar raha
        if (qr < l || r < ql) return 0;
        
        // Agar current node ka range completely query range ke andar hai
        if (ql <= l && r <= qr)
            return segTree[node].count(value) ? segTree[node][value] : 0;
        
        // Partial overlap hai, dono bachon se result le kar add kar do
        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, ql, qr, value) +
               query(2 * node + 2, mid + 1, r, ql, qr, value);
    }

public:
    // Constructor: array se segment tree build kar do
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n);  // Standard segment tree ka size 4*n hota hai
        build(arr, 0, 0, n - 1); // Root node (0) se start kar ke build karo
    }
    
    // Public function: kisi range me value ka frequency nikalne ke liye
    int rangeFreq(int left, int right, int value) {
        return query(0, 0, n - 1, left, right, value); // Root se query start karo
    }
};

class MajorityChecker {
private:
    SegmentTree* tree; // Segment tree ka pointer
    vector<int> arr;   // Original array ko store karne ke liye

public:
    // Constructor: array le kar segment tree build kar do
    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        tree = new SegmentTree(arr); // Naya segment tree banao
    }
    
    // Main query function: range [left, right] me threshold se zyada aane wala element dhundo
    int query(int left, int right, int threshold) {
        // Randomized approach: 20 baar random candidates try karo
        for (int i = 0; i < 20; ++i) {
            // Range [left, right] me se random index pick karo
            int randIdx = left + rand() % (right - left + 1);
            int candidate = arr[randIdx]; // Us index pe jo element hai, wo candidate
            
            // Is candidate ka frequency check karo segment tree se
            int freq = tree->rangeFreq(left, right, candidate);
            
            // Agar frequency threshold se zyada hai, toh ye answer hai
            if (freq >= threshold)
                return candidate;
        }
        
        // 20 attempts me koi majority element nahi mila, -1 return kar do
        return -1;
    }
    
    // Destructor: memory free kar do
    ~MajorityChecker() {
        delete tree;
    }
};

/*
POORI APPROACH KI DETAILED EXPLANATION (HINGLISH ME):

1. PROBLEM KYA KEHTI HAI:
   - Koi bhi subarray me ek element dhundo jo kam se kam 'threshold' baar aaye
   - Multiple queries hongi same array pe
   - Important constraint: 2 * threshold > subarray_length
   - Matlab sirf TRUE majority elements dhundne hain (jo 50% se zyada baar aate hain)

2. RANDOMIZED + SEGMENT TREE APPROACH KYUN USE KARI:
   
   A) Randomized kyun?
   - Agar koi element subarray me majority hai (threshold baar aata hai)
   - Aur 2*threshold > length (given constraint)
   - Matlab threshold > length/2, so ye 50% se zyada frequency hai
   - Random pick karne pe isko milne ki probability = threshold/length > 1/2
   - 20 attempts ke baad isko miss karne ki probability < (1/2)^20 ≈ 0.000001
   - Matlab almost 100% chance hai ki mil jayega

   B) Segment Tree kyun?
   - Range me kisi element ka frequency jaldi nikalna hai
   - Segment tree O(log n) me deta hai frequency
   - Build time: O(n log n), Query time: O(log n)

3. SEGMENT TREE KA STRUCTURE:
   
   Har node me: unordered_map<value, frequency> store hota hai
   
   Example array: [1, 1, 2, 2, 1, 1]
   
   Tree ka structure:
                   Root: {1:4, 2:2}  <- Total frequencies
                  /                \
           {1:2, 2:2}              {1:2}    <- Left aur right subtree
           /        \              /    \
       {1:1}      {2:2}      {1:1}    {1:1}  <- Leaf nodes
                  /    \
              {2:1}    {2:1}

4. ALGORITHM KE STEPS DETAIL ME:
   
   Build Phase:
   - 4*n size ka segment tree banao (standard size)
   - Har leaf me single element ka frequency store karo
   - Internal nodes me children ke frequencies merge kar do
   - Time complexity: O(n log n)
   
   Query Phase:
   - Subarray se random element pick karo
   - Segment tree se uska frequency nikalo
   - Agar frequency >= threshold, toh return kar do
   - Nahi toh maximum 20 baar try karo
   - Time complexity: O(20 * log n) = O(log n)

5. MATHEMATICAL PROOF KYUN KAAM KARTA HAI:
   
   - Given constraint: 2 * threshold > subarray_length
   - Matlab: threshold > subarray_length / 2
   - So valid answer hamesha TRUE majority hoga (>50% frequency)
   - Random sampling me >50% success rate per attempt
   - 20 attempts me failure probability negligible

6. EXAMPLE WALKTHROUGH:
   
   Array: [1, 1, 2, 2, 1, 1]
   Query: (0, 5, 4) // left=0, right=5, threshold=4
   
   Attempt 1: randIdx = 2, candidate = arr[2] = 2
             frequency of 2 in [0,5] = segment tree se query = 2
             2 < 4, so continue
   
   Attempt 2: randIdx = 0, candidate = arr[0] = 1
             frequency of 1 in [0,5] = segment tree se query = 4
             4 >= 4, so return 1 ✅

7. COMPLEXITY ANALYSIS:
   
   Time:
   - Constructor: O(n log n) - segment tree build karne me
   - Query: O(log n) - average me 1-2 attempts me mil jata hai
   
   Space:
   - O(n log n) - segment tree me har node me frequency maps

8. EDGE CASES:
   - Koi majority nahi: 20 attempts ke baad -1 return
   - Single element: hamesha majority hoga threshold=1 ke saath
   - Multiple valid answers: jo pehle mile wo return (rare case)

9. KYUN BETTER HAI DUSRE APPROACHES SE:
   - Brute force: O(n) per query - too slow for multiple queries
   - Deterministic algorithms: Complex implementation
   - Ye approach: Simple + Fast + High probability of correctness

10. PRACTICAL CONSIDERATIONS:
    - Given constraints (≤20k elements, ≤10k queries) ke liye perfect
    - Real-world me bahut fast kaam karta hai
    - Memory usage reasonable hai modern systems ke liye
*/