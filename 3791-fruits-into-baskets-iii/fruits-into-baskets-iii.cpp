class SegmentTree {
    // Range Maximum Query - Range mein maximum element ka INDEX return karta hai
private:
    vector<int> segTree; // Har node mein maximum element ka INDEX store hota hai (value nahi)
    vector<int> arr;     // Original array jo baskets ki capacity store karta hai
    int n;               // Array ka size

    // Segment tree ko build karta hai - O(n) time
    void build(int i, int l, int r) {
        // Base case: Agar leaf node hai (single element)
        if (l == r) {
            segTree[i] = l;  // Leaf node mein apna hi index store karo
            return;
        }
        
        // Recursive case: Left aur right subtree build karo
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid);        // Left child build karo
        build(2 * i + 2, mid + 1, r);   // Right child build karo
        
        // Current node mein left aur right child mein se maximum ka index store karo
        int leftIdx = segTree[2 * i + 1];   // Left child ka max index
        int rightIdx = segTree[2 * i + 2];  // Right child ka max index
        
        // Jo bhi zyada value hai, uska index store karo
        // Tie case mein left ko prefer karte hain (leftmost maximum)
        segTree[i] = (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
    }

    // Range [ql, qr] mein maximum element ka index return karta hai - O(log n)
    int query(int i, int l, int r, int ql, int qr) {
        // No overlap: Current segment query range ke bahar hai
        if (r < ql || l > qr) return -1;
        
        // Complete overlap: Current segment completely query range ke andar hai
        if (ql <= l && r <= qr) return segTree[i];
        
        // Partial overlap: Left aur right children se query karo
        int mid = l + (r - l) / 2;
        int left = query(2 * i + 1, l, mid, ql, qr);        // Left mein query
        int right = query(2 * i + 2, mid + 1, r, ql, qr);  // Right mein query
        
        // Results combine karo
        if (left == -1) return right;   // Left mein kuch nahi mila
        if (right == -1) return left;   // Right mein kuch nahi mila
        
        // Dono mein se maximum return karo
        return (arr[left] >= arr[right]) ? left : right;
    }

    // Single element update karta hai - O(log n)
    void update(int i, int l, int r, int idx, int value) {
        // Base case: Leaf node reached
        if (l == r) {
            arr[idx] = value;    // Original array update karo
            segTree[i] = idx;    // Segment tree node update karo
            return;
        }
        
        // Recursive case: Appropriate child mein jaao
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            update(2 * i + 1, l, mid, idx, value);      // Left child mein update
        else
            update(2 * i + 2, mid + 1, r, idx, value);  // Right child mein update
        
        // Current node ko update karo based on children
        int leftIdx = segTree[2 * i + 1];
        int rightIdx = segTree[2 * i + 2];
        segTree[i] = (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
    }

public:
    // Constructor: Array se segment tree banata hai
    SegmentTree(const vector<int>& input) {
        arr = input;
        n = arr.size();
        segTree.resize(4 * n);  // 4*n space sufficient hai segment tree ke liye
        build(0, 0, n - 1);     // Root se build start karo
    }

    // Public query function - range [l, r] mein maximum ka index
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);  // Root se query start karo
    }

    // Public update function - index idx ki value ko update karo
    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);  // Root se update start karo
    }

    // Getter function - index idx ki current value return karo
    int get(int idx) {
        return arr[idx];
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // Segment tree banao baskets array se
        SegmentTree seg(baskets);
        int unplaced = 0;  // Unplaced fruits ka counter
        int n = baskets.size();

        // Har fruit ko process karo
        for (int fruit : fruits) {
            // // Step 1: Global maximum capacity wala basket dhundo
            // int maxIdx = seg.query(0, n - 1);  // Poore range mein maximum
            
            // // Agar maximum capacity bhi fruit se kam hai, to fruit place nahi ho sakta
            // if (seg.get(maxIdx) < fruit) {
            //     unplaced++;
            //     continue;  // Next fruit pe jaao
            // }

            // Step 2: Binary search for leftmost valid basket
            // Hume leftmost basket chahiye jo fruit ko accommodate kar sake
            int l = 0, r = n - 1, ans = -1;
            
            while (l <= r) {
                int mid = (l + r) / 2;
                
                // Range [l, mid] mein maximum capacity check karo
                int idx = seg.query(l, mid);
                
                // Agar is range mein koi basket fruit accommodate kar sakta hai
                if (idx != -1 && seg.get(idx) >= fruit) {
                    ans = idx;      // Potential answer store karo
                    r = mid - 1;    // Left side mein aur leftmost dhundo
                } else {
                    l = mid + 1;    // Right side mein dhundo
                }
            }

            // Step 3: Basket use karo (mark as used)
            if (ans != -1) {
                // Basket ko use kar diya, capacity ko INT_MIN kar do (unavailable mark)
                seg.update(ans, INT_MIN);
            } else {
                // Koi valid basket nahi mila (ye case normally nahi aana chahiye)
                unplaced++;
            }
        }

        return unplaced;  // Total unplaced fruits return karo
    }
};

/*
ALGORITHM EXPLANATION (Detailed Hinglish):

PROBLEM STATEMENT:
- fruits[] array hai jisme har element fruit ka weight hai
- baskets[] array hai jisme har element basket ki capacity hai  
- Har fruit ko leftmost possible basket mein place karna hai
- Agar fruit place ho gaya to basket unavailable ho jaata hai
- Return karna hai kitne fruits place nahi ho sake

APPROACH:
1. SEGMENT TREE FOR RANGE MAXIMUM QUERY:
   - Baskets ki capacities track karte hain
   - Efficiently maximum capacity wala basket dhund sakte hain
   - Update operations bhi fast hain (O(log n))

2. GREEDY + BINARY SEARCH:
   - Har fruit ke liye leftmost valid basket dhunde hain
   - Binary search use karte hain leftmost basket find karne ke liye
   - Agar koi basket mil jaata hai to use mark kar dete hain (INT_MIN)

STEP BY STEP EXECUTION:
1. Segment tree build karo baskets se
2. Har fruit ke liye:
   a. Check karo kya koi basket fruit accommodate kar sakta hai
   b. Binary search se leftmost valid basket dhundo
   c. Basket ko unavailable mark kar do (INT_MIN set kar do)
   d. Agar koi basket nahi mila to unplaced count badhao

TIME COMPLEXITY:
- Build: O(n)
- Per fruit: O(log²n) - Binary search * Segment tree query
- Total: O(m * log²n) where m = fruits.size(), n = baskets.size()

SPACE COMPLEXITY: O(n) for segment tree

*/