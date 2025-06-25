class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0); // Step-1: Difference array

        // Step-1: Build the diff array
        for (auto& query : shifts) {
            int L = query[0];
            int R = query[1];
            int dir = query[2];
            int val = (dir == 0) ? -1 : 1;

            diff[L] += val;
            if (R + 1 < n)
                diff[R + 1] -= val;
        }

        // Step-2: Compute cumulative shift at each index
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1];
        }

        // Step-3: Apply the cumulative shift to each character
        for (int i = 0; i < n; ++i) {
            int shift = (diff[i] % 26 + 26) % 26; // Normalize to [0, 25]
            int initial = s[i] - 'a';
            s[i] = 'a' + (initial + shift) % 26;
        }

        return s;
    }
};


/*
===== ALGORITHM COMPLEXITY ANALYSIS =====

TIME COMPLEXITY: O(n + m)
- n = length of string s
- m = number of shift operations
- Processing shifts: O(m)
- Applying shifts to characters: O(n)

SPACE COMPLEXITY: O(n)
- arr array of size n+1
- No extra space for string manipulation (in-place modification)

===== WHY THIS APPROACH IS EFFICIENT =====

NAIVE APPROACH (O(n*m)):
- For each shift operation, iterate through the range and update each character
- If we have 1000 operations on a string of length 1000, we'd do 1,000,000 operations

OPTIMIZED APPROACH (O(n+m)):
- Use difference array to mark start/end of each operation: O(m)
- Calculate cumulative effect using prefix sum: O(n)
- Apply final shifts: O(n)
- Total: O(n+m) - much more efficient!

===== KEY TECHNIQUES USED =====

1. DIFFERENCE ARRAY TECHNIQUE:
   - Efficiently handle range updates
   - arr[start] += diff, arr[end+1] -= diff

2. PREFIX SUM:
   - Calculate cumulative effect at each position
   - currShift accumulates all effects up to current position

3. MODULAR ARITHMETIC:
   - Handle alphabet wrapping (z->a)
   - Handle negative shifts (left shifts)
   - (value + 26) % 26 ensures positive result

4. IN-PLACE MODIFICATION:
   - Modify initial string to save space
   - No need for additional string storage
*/


//---------------------------------------------------------------------------------------------------------

// class SegmentTree {
// private:
//     int n;                    // Size of the initial array
//     vector<int> tree;         // Segment tree array to store node values
//     vector<int> lazy;         // Lazy propagation array to store pending updates

//     // Function to push down lazy values from parent to children
//     void push(int node, int l, int r) {
//         // If current node has a pending lazy update
//         if (lazy[node] != 0) {
//             // Apply the lazy value to current node
//             tree[node] += lazy[node];
            
//             // If not a leaf node, propagate lazy value to children
//             if (l != r) {
//                 lazy[2 * node + 1] += lazy[node];     // Update left child's lazy value
//                 lazy[2 * node + 2] += lazy[node];     // Update right child's lazy value
//             }
            
//             // Clear the lazy value for current node (update applied)
//             lazy[node] = 0;
//         }
//     }

//     // Recursive function to update a range [ql, qr] with value 'val'
//     void update_Range(int node, int l, int r, int ql, int qr, int val) {
//         // First, push any pending updates for current node
//         push(node, l, r);

//         // Case 1: No overlap between current segment [l,r] and query range [ql,qr]
//         if (r < ql || l > qr) return;
        
//         // Case 2: Complete overlap - current segment is completely within query range
//         if (ql <= l && r <= qr) {
//             // Add the update value to lazy array (will be applied when needed)
//             lazy[node] += val;
//             // Immediately apply the lazy update to current node
//             push(node, l, r);
//             return;
//         }

//         // Case 3: Partial overlap - need to go to children
//         int mid = (l + r) / 2;  // Find middle point to split the range
        
//         // Recursively update left child (covers range [l, mid])
//         update_Range(2 * node + 1, l, mid, ql, qr, val);
        
//         // Recursively update right child (covers range [mid+1, r])
//         update_Range(2 * node + 2, mid + 1, r, ql, qr, val);
        
//         // Note: tree[node] = 0 is not needed for this problem since we only do point queries
//         // In problems requiring range sum queries, you'd combine children values here
//         tree[node] = 0; // Placeholder - not used in this implementation
//     }

//     // Function to query the value at a specific index
//     int query(int node, int l, int r, int idx) {
//         // Apply any pending lazy updates to current node
//         push(node, l, r);

//         // Base case: if we've reached a leaf node (l == r), return its value
//         if (l == r) return tree[node];

//         // Recursive case: determine which child contains our target index
//         int mid = (l + r) / 2;

//         // If target index is in left half, go to left child
//         if (idx <= mid)
//             return query(2 * node + 1, l, mid, idx);
//         // Otherwise, target index is in right half, go to right child
//         else
//             return query(2 * node + 2, mid + 1, r, idx);
//     }

// public:
//     // Constructor: Initialize segment tree for array of given size
//     SegmentTree(int size) {
//         n = size;
//         // Segment tree needs at most 4*n nodes to represent all ranges
//         tree.assign(4 * n, 0);    // Initialize all tree nodes to 0
//         lazy.assign(4 * n, 0);    // Initialize all lazy values to 0
//     }

//     // Public interface for range update: add 'val' to all elements in range [l, r]
//     void update(int l, int r, int val) {
//         // Call internal update_Range starting from root (node 0, covering range [0, n-1])
//         update_Range(0, 0, n - 1, l, r, val);
//     }

//     // Public interface for point query: get value at specific index
//     int get(int idx) {
//         // Call internal query starting from root (node 0, covering range [0, n-1])
//         return query(0, 0, n - 1, idx);
//     }
// };

// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         int n = s.length();
        
//         // Create segment tree to efficiently handle range updates
//         SegmentTree st(n);

//         // Process all shift operations
//         for (const auto& shift : shifts) {
//             int l = shift[0];      // Start index of range to shift
//             int r = shift[1];      // End index of range to shift
//             int dir = shift[2];    // Direction: 1 = forward, 0 = backward
            
//             // Convert direction to actual shift value
//             int val = (dir == 1) ? 1 : -1;  // +1 for forward shift, -1 for backward
            
//             // Apply range update: add 'val' to all positions in range [l, r]
//             st.update(l, r, val);
//         }

//         // Apply accumulated shifts to each character in the string
//         for (int i = 0; i < n; ++i) {
//             // Get total shift amount for position i
//             int shift = st.get(i) % 26;  // Use modulo 26 since alphabet has 26 letters
            
//             // Handle negative shifts (convert to positive equivalent)
//             if (shift < 0) shift += 26;
            
//             // Apply the shift to character:
//             // 1. Convert char to 0-based index: (s[i] - 'a')
//             // 2. Add shift amount: (s[i] - 'a' + shift)
//             // 3. Use modulo to wrap around: (s[i] - 'a' + shift) % 26
//             // 4. Convert back to character: 'a' + result
//             s[i] = 'a' + (s[i] - 'a' + shift) % 26;
//         }

//         return s;  // Return the modified string
//     }
// };

/*
=====================================================================================
                    DETAILED EXPLANATION OF THE CODE STRUCTURE
=====================================================================================

PROBLEM OVERVIEW:
-----------------
The "Shifting Letters" problem requires us to:
1. Take a string and multiple shift operations
2. Each shift operation affects a range [l,r] and shifts characters forward/backward
3. Apply all shifts and return the final string

NAIVE APPROACH ISSUES:
---------------------
- For each shift operation, update every character in range [l,r]
- Time Complexity: O(n*m) where n=string length, m=number of shifts
- This becomes too slow for large inputs (can be up to 10^5 operations on 10^5 length string)

SEGMENT TREE WITH LAZY PROPAGATION SOLUTION:
-------------------------------------------

1. CORE CONCEPT:
   - Instead of updating individual characters, we store "shift amounts" for ranges
   - Use lazy propagation to defer actual updates until we need to query
   - This reduces range updates from O(n) to O(log n)

2. DATA STRUCTURES:
   - tree[]: Stores the actual shift values at each node
   - lazy[]: Stores pending updates that haven't been pushed down yet
   - Node indexing: For node i, left child = 2*i+1, right child = 2*i+2

3. KEY OPERATIONS:

   a) PUSH OPERATION:
      - Purpose: Apply pending lazy updates to current node
      - When called: Before any operation on a node
      - Action: Add lazy[node] to tree[node], propagate to children if not leaf
      - Why needed: Ensures node has correct value before we use it

   b) RANGE UPDATE:
      - Three cases based on overlap between current segment and query range:
        * No overlap: Return immediately
        * Complete overlap: Mark lazy update and push
        * Partial overlap: Recursively update both children
      - Lazy propagation ensures O(log n) complexity per update

   c) POINT QUERY:
      - Navigate from root to leaf corresponding to target index
      - Apply push() at each level to get correct accumulated value
      - Return the final value at the leaf

4. MEMORY LAYOUT:
   - Segment tree uses array representation
   - For array of size n, we need 4*n space in worst case
   - Index 0 is root, represents range [0, n-1]
   - Level by level: root->children->grandchildren...

5. ALGORITHM FLOW:
   Step 1: Initialize segment tree with all zeros
   Step 2: For each shift operation, call update(l, r, shift_value)
   Step 3: For each character position i, call get(i) to find total shift
   Step 4: Apply shift to character: new_char = (old_char + shift) % 26

6. WHY THIS WORKS:
   - Multiple shifts on overlapping ranges get accumulated correctly
   - Lazy propagation ensures we don't do unnecessary work
   - Final query gives us the sum of all shifts affecting each position

7. EXAMPLE WALKTHROUGH:
   String: "abc", Shifts: [[0,1,1], [1,2,1], [0,2,0]]
   
   After shift [0,1,1]: positions 0,1 get +1 shift
   After shift [1,2,1]: positions 1,2 get additional +1 shift
   After shift [0,2,-1]: positions 0,1,2 get additional -1 shift
   
   Final shifts: pos[0]=0, pos[1]=+1, pos[2]=0
   Result: "abc" -> "abc" (a+0=a, b+1=c, c+0=c) -> "acc"

COMPLEXITY ANALYSIS:
-------------------
Time Complexity:
- Tree construction: O(n)
- Each range update: O(log n) due to tree height
- Each point query: O(log n)
- Total: O(n + m*log n + n*log n) = O((m+n)*log n)

Space Complexity:
- Segment tree arrays: O(4*n) = O(n)
- Recursion stack: O(log n)
- Total: O(n)

ADVANTAGES OVER BRUTE FORCE:
---------------------------
1. Efficiency: O((m+n)*log n) vs O(n*m)
2. Scalability: Handles large inputs efficiently
3. Memory: Only O(n) extra space needed
4. Generality: Can be extended for other range operations

WHEN TO USE THIS APPROACH:
-------------------------
- Multiple range updates followed by point queries
- Range updates with point queries (like this problem)
- When brute force O(n*m) is too slow
- Problems involving cumulative effects over ranges

POTENTIAL VARIATIONS:
--------------------
- Range sum queries: Modify to combine children values
- Range minimum/maximum: Change combination function
- Multiple types of updates: Extend lazy propagation
- 2D version: Use 2D segment tree for matrix operations
*/