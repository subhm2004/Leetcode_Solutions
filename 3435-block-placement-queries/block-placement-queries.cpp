class SegmentTree {
    vector<int> segTree;
    int size;

public:
    // Constructor: maxVal tak ke liye segment tree banate hai
    SegmentTree(int maxVal) {
        size = maxVal + 1;
        segTree.resize(4 * size, 0);  // 4*size space chahiye segment tree ke liye
    }

    // Range Query Maximum: [ql, qr] range mein maximum value nikalta hai
    int query(int i, int l, int r, int ql, int qr) {
        // Agar query range bilkul bahar hai current node range se
        if (qr < l || r < ql) return 0; // completely outside

        // Agar current node range pura query range ke andar hai
        if (ql <= l && r <= qr) return segTree[i]; // completely inside

        // Partial overlap: kuch part andar hai, kuch bahar
        int mid = (l + r) / 2;
        return max(
            query(2*i+1, l, mid, ql, qr),      // Left child se query
            query(2*i+2, mid+1, r, ql, qr)     // Right child se query
        );
    }

    // Point Update: index `idx` pe val set karta hai (max wala nahi, direct set)
    void update(int i, int l, int r, int idx, int val) {
        // Agar leaf node hai (l == r), directly update kar do
        if (l == r) {
            segTree[i] = val;  // Direct set karo (gap replace hota hai)
            return;
        }

        int mid = (l + r) / 2;
        // Decide karo ki left subtree mein jana hai ya right mein
        if (idx <= mid)
            update(2*i+1, l, mid, idx, val);   // Left child update
        else
            update(2*i+2, mid+1, r, idx, val); // Right child update

        // Current node ko update karo using child nodes ka maximum
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    }

    // Public wrapper function: range query ke liye
    int query_Range(int l, int r) {
        if (l > r) return 0; // Edge case: invalid range
        return query(0, 0, size-1, l, r);
    }

    // Public wrapper function: point update ke liye
    void update_Index(int idx, int val) {
        update(0, 0, size-1, idx, val);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int maxVal = 50001;
        SegmentTree st(maxVal);

        set<int> obstacles;  // Current obstacles ki positions
        obstacles.insert(0); // Default obstacle at 0 (boundary)
        obstacles.insert(maxVal); // Right boundary bhi daal do safety ke liye

        vector<bool> result;

        for (auto& query : queries) {

            if (query[0] == 1) {
                // ─── Type 1: Obstacle add karo at position x ───
                int x = query[1];

                // x ke aas paas ke obstacles dhundo
                auto it  = obstacles.upper_bound(x); // x ke baad wala
                int nxt  = *it;                      // next obstacle
                int pre  = *prev(it);                // previous obstacle

                // x ko add karne se do nayi gaps banti hain:
                // Gap between pre and x
                st.update_Index(x, x - pre);

                // Gap between x and nxt shrink hoti hai
                // nxt ki purani gap (nxt-pre) replace hogi (nxt-x) se
                st.update_Index(nxt, nxt - x);

                obstacles.insert(x);

            } else {
                // ─── Type 2: Check karo koi gap >= sz hai [0, x] mein ───
                int x  = query[1];
                int sz = query[2];

                // x se pehla obstacle dhundo
                auto it = obstacles.upper_bound(x);
                int pre = *prev(it); // x se just pehle wala obstacle

                // [0, pre] range mein maximum gap (segment tree se)
                int maxGap = st.query_Range(0, pre);

                // x aur pre ke beech wali gap bhi check karo
                // (ye segment tree mein nahi hai abhi kyunki x pe koi obstacle nahi)
                int lastGap = x - pre;

                int best = max(maxGap, lastGap);

                result.push_back(best >= sz);
            }
        }

        return result;
    }
};