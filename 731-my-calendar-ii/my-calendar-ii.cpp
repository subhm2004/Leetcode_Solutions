// class MyCalendarTwo {
//     vector<pair<int, int>> singleBookings;
//     vector<pair<int, int>> doubleBookings;

// public:
//     bool book(int start, int end) {
//         // 1. Check: Will this booking cause a triple booking?
//         for (const auto& [ds, de] : doubleBookings) {
//             // If overlap with any double booking → triple booking
//             if (start < de && end > ds) {
//                 return false;
//             }
//         }

//         // 2. Update doubleBookings if it overlaps with any existing singleBooking
//         for (const auto& [ss, se] : singleBookings) {
//             // If overlap → that part is now a double booking
//             if (start < se && end > ss) {
//                 int overlap_Start = max(start, ss);
//                 int overlap_End = min(end, se);
//                 doubleBookings.push_back({overlap_Start, overlap_End});
//             }
//         }

//         // 3. Finally add the event to singleBookings
//         singleBookings.push_back({start, end});
//         return true;
//     }
// };

class SegmentTree {
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
        if (!node) return 0;
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
class MyCalendarTwo {
    SegmentTree seg;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Check if this booking will cause a triple booking
        if (seg.query(start, end - 1) >= 2)
            return false;

        // Otherwise, update the segment tree and book it
        seg.update(start, end - 1, 1);
        return true;
    }
};