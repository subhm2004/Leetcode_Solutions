class Segment_Tree {
private:
    vector<int> segTree;
    vector<int> lazy;
    int n;

    void build(const vector<int>& arr, int i, int l, int r) {
        if (l == r) {
            segTree[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * i + 1, l, mid);
        build(arr, 2 * i + 2, mid + 1, r);
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    // ── push: SIRF YAHAN CHANGE KIYA ─────────────────────────────────────────
    //   Pehle: segTree[i] += lazy[i]  (ADD)
    //   Ab   : segTree[i] = max(segTree[i], lazy[i])  (MAX ASSIGN)
    //
    //   Kyun MAX ASSIGN?
    //     Overlapping buildings me badi height jeetti hai
    //     [2,9,10] aur [3,7,15] overlap pe → max(10,15) = 15 ✓
    //     ADD se 10+15=25 aata tha → WRONG ✗
    //
    //   Bachon ko bhi same treatment:
    //     lazy[child] = max(lazy[child], lazy[i])
    //     Agar bacche ka existing lazy bada hai → mat chhedo
    void push(int i, int l, int r) {
        if (lazy[i] != 0) {
            segTree[i] = max(segTree[i], lazy[i]); // ← MAX ASSIGN (was +=)
            if (l != r) {
                lazy[2 * i + 1] = max(lazy[2 * i + 1], lazy[i]); // ← MAX (was +=)
                lazy[2 * i + 2] = max(lazy[2 * i + 2], lazy[i]); // ← MAX (was +=)
            }
            lazy[i] = 0;
        }
    }

    // ── update_Range: same as tera — sirf push() change ka effect aayega ─────
    void update_Range(int i, int l, int r, int start, int end, int val) {
        push(i, l, r);
        if (r < start || l > end)
            return;
        if (start <= l && r <= end) {
            lazy[i] = max(lazy[i], val); 
            push(i, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update_Range(2 * i + 1, l, mid, start, end, val);
        update_Range(2 * i + 2, mid + 1, r, start, end, val);
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    // ── query_Range: bilkul same as tera — kuch nahi badla ───────────────────
    int query_Range(int i, int l, int r, int start, int end) {
        push(i, l, r);
        if (r < start || l > end)
            return 0;
        if (start <= l && r <= end)
            return segTree[i];
        int mid = (l + r) / 2;
        return max(query_Range(2 * i + 1, l, mid, start, end),
                   query_Range(2 * i + 2, mid + 1, r, start, end));
    }

public:
    Segment_Tree(const vector<int>& arr) {
        n = (int)arr.size();
        segTree.assign(4 * max(n, 1), 0);
        lazy.assign(4 * max(n, 1), 0);
        if (n > 0)
            build(arr, 0, 0, n - 1);
    }
    void update_Range(int l, int r, int val) {
        update_Range(0, 0, n - 1, l, r, val);
    }
    int query_Range(int l, int r) { return query_Range(0, 0, n - 1, l, r); }
};

// ════════════════════════════════════════════════════════════════════════════
// Coordinate_Compression — teri class as-is
// ════════════════════════════════════════════════════════════════════════════
class Coordinate_Compression {
public:
    unordered_map<int, int> compress;
    vector<int> rev_map;

    Coordinate_Compression(const vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        int id = 0;
        for (int x : st) {
            compress[x] = id;
            rev_map.push_back(x);
            id++;
        }
    }
    int get_original(int val) const { return rev_map[val]; }
    int size() const { return (int)rev_map.size(); }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        // Step 1: coords collect karo
        vector<int> coords;
        for (auto& b : buildings) {
            coords.push_back(b[0]);
            coords.push_back(b[1]);
        }

        // Step 2: compress karo
        Coordinate_Compression cc(coords);
        int m = cc.size();

        // Step 3: seg tree — saari heights 0 se
        vector<int> init(m, 0);
        Segment_Tree seg(init);

        // Step 4: har building ke liye range update
        // [l, r, h] → compressed [li, ri-1] pe h assign
        // ri-1 kyun? right edge exclusive hai — building x=r pe NAHI hoti
        for (auto& b : buildings) {
            int li = cc.compress[b[0]];
            int ri = cc.compress[b[1]] - 1;
            if (li <= ri)
                seg.update_Range(li, ri, b[2]);
        }

        // Step 5: scan — height change pe key point
        vector<vector<int>> result;
        int prevH = 0;
        for (int i = 0; i < m; i++) {
            int currH = seg.query_Range(i, i); // point query
            int x = cc.get_original(i);
            if (currH != prevH) {
                result.push_back({x, currH});
                prevH = currH;
            }
        }
        return result;
    }
};