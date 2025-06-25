class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        // PRIORITY QUEUES KA EXPLANATION:
        
        // 1. MIN-HEAP: Abhi jo queries chal rahi hain unka END index store karta hai
        // Kyun min-heap? Jaldi se pata chal jaye ki konsi query pehle khatam hogi
        // Contains: jo queries abhi array elements ko reduce kar rahi hain unka end index
        priority_queue<int, vector<int>, greater<int>> past;
        
        // 2. MAX-HEAP: Jo queries available hain (unused) unka END index store karta hai
        // Kyun max-heap? Hum chahte hain BADE end indices wali queries (zyada coverage)
        // Greedy choice: Lambi wali queries use karo taaki flexibility zyada rahe
        priority_queue<int> maxHeap;
        
        // PREPROCESSING: Queries ko START index ke hisaab se sort karo
        // Isse left-to-right process karte time queries milti jayengi
        sort(queries.begin(), queries.end());
        
        int j = 0;        // Sorted queries mein iterate karne ke liye pointer
        int usedCount = 0; // Kitni queries actually use kiye count karta hai
        
        // MAIN ALGORITHM: Har position ko left se right process karo
        for (int i = 0; i < n; ++i) {
            
            // STEP 1: NAYE QUERIES DHUNDO
            // Jo queries position i par START hoti hain unhe available pool mein daal do
            while (j < queries.size() && queries[j][0] == i) {
                maxHeap.push(queries[j][1]); // Sirf END index store karo (start toh i hai)
                ++j;
            }
            
            // STEP 2: ACTIVE QUERIES KA EFFECT LAGAO
            // 'past' mein jo queries hain wo abhi active hain aur nums[i] ko reduce karti hain
            // Har active query current position ko 1 se kam karti hai
            nums[i] -= past.size();
            
            // STEP 3: GREEDY SELECTION - NAYE QUERIES CHOOSE KARO
            // Agar nums[i] abhi bhi positive hai, toh aur reduction chahiye
            // Sabse lambi coverage wali queries ko greedily select karo
            while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
                // maxHeap.top() >= i ye ensure karta hai ki query current position ko cover karti hai
                
                int r = maxHeap.top(); // Maximum end index wali query lo
                maxHeap.pop();         // Available pool se hata do
                
                past.push(r);          // Active queries mein add kar do
                usedCount++;           // Usage counter badhao
                nums[i]--;             // Turant reduction apply karo
                
                // YE KYUN OPTIMAL HAI:
                // - Sirf zarurat padne par queries use karte hain (lazy approach)
                // - Bade end indices wali queries prefer karte hain (future flexibility)
                // - Local optimal choices jo global optimum deti hain
            }
            
            // STEP 4: FEASIBILITY CHECK
            // Agar abhi bhi nums[i] ko 0 nahi kar sake, toh problem solve nahi ho sakti
            if (nums[i] > 0) {
                return -1; // Koi solution exist nahi karta
            }
            
            // STEP 5: EXPIRED QUERIES KO SAAF KARO
            // Jo queries current position par khatam hoti hain unhe active set se hata do
            // Ye queries ab future positions ko affect nahi karengi
            while (!past.empty() && past.top() == i) {
                past.pop(); // Query expire ho gayi, active set se hata do
            }
            
            // Is point par: nums[i] <= 0 (successfully reduce ho gaya)
        }
        
        // FINAL RESULT: Maximum kitni queries remove kar sakte hain
        // Total queries - Used queries = Removed queries
        return queries.size() - usedCount;
    }
};

/* 
ALGORITHM KA DETAILED EXPLANATION:
=================================

PROBLEM SAMJHO:
- Ek array nums[] diya gaya hai
- Queries diye gaye hain [start, end] format mein
- Har query apne range mein har element ko 1 se reduce karti hai
- Goal: Maximum kitni queries remove kar sakte hain such ki baaki queries se saare elements 0 ya negative ho jaayen

KEY INSIGHTS:
1. GREEDY STRATEGY: Sirf zarurat padne par queries use karo
2. PRIORITY ORDERING: Lambi coverage wali queries ko prefer karo
3. LEFT-TO-RIGHT PROCESSING: Position-wise constraints handle karo
4. LAZY EVALUATION: Query selection ko last moment tak defer karo

DATA STRUCTURE CHOICES:
1. MIN-HEAP (past): Active queries kab expire hongi track karo
2. MAX-HEAP (maxHeap): Best available queries select karo
3. SORTING: Queries ko start position se process karo

ALGORITHM STEPS:
1. Queries ko start index se sort karo
2. Har position i ke liye:
   - Naye queries ko available pool mein add karo
   - Active queries ka effect apply karo
   - Agar nums[i] > 0, toh best available queries use karo
   - Expired queries ko clean up karo

TIME COMPLEXITY: O(Q log Q + N log Q) jahan Q = queries, N = array size
SPACE COMPLEXITY: O(Q) priority queues ke liye

EXAMPLE WALKTHROUGH:
===================
nums = [0,5,5], queries = [[0,1],[0,2],[1,1],[1,2],[1,2],[1,2],[2,2]]

Position i=0:
- Available queries: [0,1],[0,2] → maxHeap = [2,1]
- nums[0] = 0, koi reduction nahi chahiye
- usedCount = 0

Position i=1:
- Available queries: [1,1],[1,2],[1,2],[1,2] → maxHeap = [2,2,2,2,1]
- nums[1] = 5, 5 reductions chahiye
- Queries use karo ending at: 2,2,2,2,1 → usedCount = 5
- past = [1,2,2,2,2], nums[1] = 0
- Expired queries remove: past = [2,2,2,2]

Position i=2:
- Available queries: [2,2] → maxHeap = [2]
- nums[2] = 5 - 4 = 1 (4 active queries reduce kar rahe hain)
- 1 aur query use karo → usedCount = 6
- nums[2] = 0

Result: 7 - 6 = 1 query remove kar sakte hain

INTUITION:
----------
- Ye ek greedy algorithm hai jo "lazy evaluation" use karti hai
- Hum tab tak queries use nahi karte jab tak zarurat nahi padti
- Jab zarurat padti hai, toh sabse lambi coverage wali query choose karte hain
- Isse maximum flexibility milti hai future positions ke liye
- Min-heap expired queries track karta hai, max-heap best available queries deta hai
*/