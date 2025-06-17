class SegmentTree {
    // \U0001f539 Har node me store hoga: segment ka info
    struct Node {
        int max_Len;        // longest repeating character substring in current segment
        char left_Char;     // leftmost character of the segment
        int left_Len;       // kitne consecutive left_Char hain left se
        char right_Char;    // rightmost character of the segment
        int right_Len;      // kitne consecutive right_Char hain right se
        int l, r;           // segment ka range [l, r]
    };

    int n;  // input string ki length
    vector<Node> segTree;  // segment tree of Nodes

    // \U0001f539 Do nodes ko merge karne ka logic
    Node merge(const Node& left, const Node& right) {
        Node ans;

        // merged node ka range
        ans.l = left.l;
        ans.r = right.r;

        // leftmost and rightmost characters set karo
        ans.left_Char = left.left_Char;
        ans.right_Char = right.right_Char;

        // \U0001f7e1 Calculate left_Len
        ans.left_Len = left.left_Len;
        // Agar poora left segment ek hi char se bana ho
        // aur uska last char == right ka first char ho,
        // toh dono ka count add kar do
        if (left.left_Len == (left.r - left.l + 1) && left.right_Char == right.left_Char) {
            ans.left_Len += right.left_Len;
        }

        // \U0001f7e1 Calculate right_Len
        ans.right_Len = right.right_Len;
        // Same logic right side ke liye
        if (right.right_Len == (right.r - right.l + 1) && right.left_Char == left.right_Char) {
            ans.right_Len += left.right_Len;
        }

        // \U0001f7e1 Calculate max_Len (maximum repeating substring in the segment)
        ans.max_Len = max(left.max_Len, right.max_Len);
        // Agar boundary pe characters same hain, toh middle join ho sakta hai
        if (left.right_Char == right.left_Char) {
            ans.max_Len = max(ans.max_Len, left.right_Len + right.left_Len);
        }

        return ans;
    }

    // \U0001f539 Segment Tree Build karna — recursive function
    void build(const string& s, int node, int l, int r) {
        // Base case: leaf node (single character)
        if (l == r) {
            segTree[node] = {1, s[l], 1, s[l], 1, l, r};
            return;
        }

        // Recursive calls: left and right child
        int mid = (l + r) / 2;
        build(s, 2 * node + 1, l, mid);
        build(s, 2 * node + 2, mid + 1, r);

        // Merge left and right child
        segTree[node] = merge(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    // \U0001f539 Update function — kisi index ka character change karna ho
    void update(int node, int l, int r, int idx, char val) {
        // Base case: leaf node
        if (l == r) {
            segTree[node] = {1, val, 1, val, 1, l, r};
            return;
        }

        // Go to correct child
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node + 1, l, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, r, idx, val);

        // After update, re-merge this node
        segTree[node] = merge(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

public:
    // \U0001f539 Constructor: build tree from given string
    SegmentTree(const string& s) {
        n = s.size();
        segTree.resize(4 * n); // segment tree size
        build(s, 0, 0, n - 1); // start building from root
    }

    // \U0001f539 Public update method
    void update(int idx, char val) {
        update(0, 0, n - 1, idx, val);
    }

    // \U0001f539 Get longest repeating substring in entire string
    int get_Max_Len() {
        return segTree[0].max_Len;
    }
};
class Solution { // Dynamic Memory allocate krke kiya hai 
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree* seg = new SegmentTree(s);  // \U0001f539 SegmentTree ka pointer banaya

        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); ++i) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];
            seg->update(idx, ch);  // \U0001f539 Pointer se update
            ans.push_back(seg->get_Max_Len());  // \U0001f539 Pointer se max len lena
        }

        delete seg;  // \U0001f539 Memory cleanup
        return ans;
    }
};

// class Solution { // Static Memory allocate krke kiya hai 
// public:
//     vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
//         SegmentTree segTree(s); // \U0001f539 segment tree banao input string se
//         vector<int> ans;

//         for (int i = 0; i < queryIndices.size(); ++i) {
//             int idx = queryIndices[i];
//             char ch = queryCharacters[i];

//             segTree.update(idx, ch); // \U0001f539 update character at index
//             ans.push_back(segTree.get_Max_Len()); // \U0001f539 push current longest repeating substring
//         }

//         return ans;  
//     }
// };