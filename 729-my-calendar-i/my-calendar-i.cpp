// class MyCalendar {
//     vector<pair<int, int>> bookings;

// public:
//     MyCalendar() {
//         // Initially, no bookings
//     }

//     bool book(int start, int end) {
//         for (auto [s, e] : bookings) {
//             // If overlap found
//             if (start < e && s < end) {
//                 return false;
//             }
//         }
//         // If no overlap, add the booking
//         bookings.emplace_back(start, end);
//         return true;
//     }
// };



// class SegmentTree {        // Static Segment Tree hai MLE aayega isme 
// private:
//     vector<long> segTree;
//     vector<long> lazy;
//     int n;

//     void build(const vector<int> &arr, int i, int l, int r) {
//         if (l == r) {
//             segTree[i] = arr[l];
//             return;
//         }
//         int mid = (l + r) / 2;
//         build(arr, 2 * i + 1, l, mid);
//         build(arr, 2 * i + 2, mid + 1, r);
//         segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
//     }

//     void push(int i, int l, int r) {
//         if (lazy[i] != 0) {
//             segTree[i] += lazy[i]; // Apply lazy increment
//             if (l != r) {
//                 lazy[2 * i + 1] += lazy[i];
//                 lazy[2 * i + 2] += lazy[i];
//             }
//             lazy[i] = 0;
//         }
//     }

//     void update_Range(int i, int l, int r, int start, int end, int val) {
//         push(i, l, r);
//         if (r < start || l > end)
//             return;
//         if (start <= l && r <= end) {
//             lazy[i] += val;
//             push(i, l, r);
//             return;
//         }
//         int mid = (l + r) / 2;
//         update_Range(2 * i + 1, l, mid, start, end, val);
//         update_Range(2 * i + 2, mid + 1, r, start, end, val);
//         segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
//     }

//     long query_Max(int i, int l, int r, int start, int end) {
//         push(i, l, r);
//         if (r < start || l > end)
//             return LLONG_MIN;
//         if (start <= l && r <= end)
//             return segTree[i];
//         int mid = (l + r) / 2;
//         return max(
//             query_Max(2 * i + 1, l, mid, start, end),
//             query_Max(2 * i + 2, mid + 1, r, start, end)
//         );
//     }

// public:
//     SegmentTree(const vector<int> &arr) {
//         n = arr.size();
//         segTree.resize(4 * n);
//         lazy.resize(4 * n, 0);
//         build(arr, 0, 0, n - 1);
//     }

//     void update_Range(int l, int r, int val) {
//         update_Range(0, 0, n - 1, l, r, val);
//     }

//     long queryMax(int l, int r) {
//         return query_Max(0, 0, n - 1, l, r);
//     }
// };
// class MyCalendar {
//     SegmentTree seg;

// public:
//     MyCalendar() : seg(vector<int>(1e9 +1, 0)) {} // Calendar range [0, 1e9]

//     bool book(int start, int end) {
//         if (seg.queryMax(start, end - 1) >= 1) {
//             return false; // Overlap exists → double booking not alongowed
//         }
//         seg.update_Range(start, end - 1, 1); // Book the event
//         return true;
//     }
// };


class SegmentTree {           // Dynamic Segmemt Tree with Lazy Propofation Fixed Size ka nhi hai jitni values hai unke liye hi use krr rhe hai hum 
private:   
    struct Node {
        long val = 0;
        long lazy = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root;
    const int MAX_RANGE = 1e9;

    void push(Node* node, int l, int r) {
        if (!node->left) node->left = new Node();
        if (!node->right) node->right = new Node();

        if (node->lazy != 0) {
            node->val += node->lazy;
            if (l != r) {
                node->left->lazy += node->lazy;
                node->right->lazy += node->lazy;
            }
            node->lazy = 0;
        }
    }

    void update(Node* node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            node->lazy += val;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(node->left, l, mid, ql, qr, val);
        update(node->right, mid + 1, r, ql, qr, val);
        node->val = max(node->left->val, node->right->val);
    }

    long query(Node* node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return node->val;

        int mid = (l + r) / 2;
        return max(
            query(node->left, l, mid, ql, qr),
            query(node->right, mid + 1, r, ql, qr)
        );
    }

public:
    SegmentTree() {
        root = new Node();
    }

    void update(int l, int r, int val) {
        update(root, 0, MAX_RANGE, l, r, val);
    }

    long query(int l, int r) {
        return query(root, 0, MAX_RANGE, l, r);
    }
};

class MyCalendar {
    SegmentTree seg;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        if (seg.query(start, end - 1) >= 1)
            return false;
        seg.update(start, end - 1, 1);
        return true;
    }
};
