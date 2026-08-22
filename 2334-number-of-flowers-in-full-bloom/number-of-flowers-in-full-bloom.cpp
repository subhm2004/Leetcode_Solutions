// Dynamic (sparse / lazy-created) Segment Tree
// Range Update (add) + Point Query
const int MAX_RANGE = 1e9;

class SegmentTree {
private:
    struct Node {
        int val  = 0;   // is node ka apna value (point query me leaf ka val hi final answer hota hai)
        int lazy = 0;   // pending add jo abhi tak is node par apply nahi hua
        Node *left = nullptr, *right = nullptr;  // children ON DEMAND banenge (isliye "dynamic")
    };

    Node* root;

    // push = lazy ko current node par apply karo + children me neeche bhejo
    void push(Node* node, int l, int r) {
        // Children exist nahi karte to bana do.
        // NOTE: ye yahan galat jagah hai — leaf (l == r) par bhi children ban rahe hain = pure waste
        if (!node->left)  node->left  = new Node();
        if (!node->right) node->right = new Node();

        if (node->lazy != 0) {
            // pending add ko khud par apply karo
            node->val += node->lazy;

            // agar leaf nahi hai to lazy children ko forward kar do
            if (l != r) {
                node->left->lazy  += node->lazy;
                node->right->lazy += node->lazy;
            }
            node->lazy = 0;   // clear, warna dobara apply ho jayega
        }
    }

    void update(Node* node, int l, int r, int ql, int qr, int val) {
        // pehle pending lazy settle karo taki node ka state current ho
        // NOTE: ye call range-check se PEHLE hai → out-of-range nodes ke bhi children allocate ho rahe hain
        push(node, l, r);

        // Case 1: [l, r] aur [ql, qr] ka koi overlap nahi → kuch mat karo
        if (r < ql || l > qr) return;

        // Case 2: [l, r] poora [ql, qr] ke andar hai → lazy laga do, neeche mat jao
        if (ql <= l && r <= qr) {
            node->lazy += val;
            push(node, l, r);   // turant apply (taki node->val current rahe)
            return;
        }

        // Case 3: partial overlap → dono taraf recurse
        int mid = (l + r) / 2;   //  l, r yahan 0..1e9 hain, overflow nahi hoga, par (l + (r-l)/2) safer habit hai
        update(node->left,  l,       mid, ql, qr, val);
        update(node->right, mid + 1, r,   ql, qr, val);

        // internal node ka aggregate. Point query ke liye ye value kabhi padhi hi nahi jaati,
        // isliye "sum" semantics yahan meaningless hai (niche issue #4 dekh)
        node->val = node->left->val + node->right->val;
    }

    int query(Node* node, int l, int r, int pos) {
        push(node, l, r);   // ancestors ka lazy neeche flow karta hua leaf tak pahunchega
        if (l == r) return node->val;   // leaf mila → yahi answer

        int mid = (l + r) / 2;
        if (pos <= mid) return query(node->left,  l,       mid, pos);
        else            return query(node->right, mid + 1, r,   pos);
    }

public:
    SegmentTree() { root = new Node(); }   // sirf root; baaki tree on-demand banega

    void update(int l, int r, int val) { update(root, 0, MAX_RANGE, l, r, val); }
    int  query(int pos)                { return query(root, 0, MAX_RANGE, pos); }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // ---- Coordinate Compression ----
        // set → automatically sorted + duplicates hata deta hai
        set<int> coordinates;
        for (auto& f : flowers) { coordinates.insert(f[0]); coordinates.insert(f[1]); }
        for (int t : people)      coordinates.insert(t);

        // actual time value → chhota index (0, 1, 2, ...)
        unordered_map<int, int> compress;
        int idx = 0;
        for (int x : coordinates) compress[x] = idx++;

        SegmentTree seg;

        // Har flower [start, end] par +1 ka range add
        // Matlab: "is time-interval me jo bhi din aata hai, uske count me 1 add"
        for (auto& f : flowers) {
            int l = compress[f[0]];
            int r = compress[f[1]];
            seg.update(l, r, 1);
        }

        // Har person ke time par point query → kitne flowers overlap kar rahe hain
        vector<int> ans;
        for (int t : people) ans.push_back(seg.query(compress[t]));

        return ans;
    }
};