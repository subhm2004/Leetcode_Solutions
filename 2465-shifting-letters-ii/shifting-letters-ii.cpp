// class Solution {
//  public:
//   string shiftingLetters(string s, vector<vector<int>>& shifts) {
//     int currShift = 0; // Har character ke liye cumulative (total) shift track karne ke liye variable

//     // Timeline vector banate hain jisme har position par shift ka effect track hoga
//     vector<int> timeline(s.length() + 1);

//     // Har shift operation ke liye update karte hain timeline array ko
//     for (const vector<int>& shift : shifts) {
//       const int start = shift[0]; // Shift ka starting index
//       const int end = shift[1];   // Shift ka ending index
//       const int direction = shift[2]; // 1 matlab right shift, 0 matlab left shift

//       const int diff = direction ? 1 : -1; // Direction ke hisaab se shift ka sign decide karte hain
//       timeline[start] += diff;       // Start index se shift ka effect shuru
//       timeline[end + 1] -= diff;     // End ke baad shift ka effect khatam
//     }

//     // Prefix sum nikal kar actual shift calculate karte hain har character ke liye
//     for (int i = 0; i < s.length(); ++i) {
//       currShift = (currShift + timeline[i]) % 26; // Total shift ko 26 se mod karte hain kyunki 26 letters hi hote hain
//       const int num = (s[i] - 'a' + currShift + 26) % 26; // Shifted character ka naya position nikalte hain, +26 overflow se bachne ke liye
//       s[i] = 'a' + num; // ASCII value se naya character banate hain
//     }

//     return s; // Final shifted string return karte hain
//   }
// };



class SegmentTree {
private:
    int n;
    vector<int> tree, lazy;

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (l != r) {
                lazy[2 * node + 1] += lazy[node];     // left child (0-based)
                lazy[2 * node + 2] += lazy[node];     // right child
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);

        if (r < ql || l > qr) return; // No overlap
        if (ql <= l && r <= qr) {     // Complete overlap
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;
        updateRange(2 * node + 1, l, mid, ql, qr, val);
        updateRange(2 * node + 2, mid + 1, r, ql, qr, val);
        tree[node] = 0; // Not needed, just a placeholder
    }

    int query(int node, int l, int r, int idx) {
        push(node, l, r);

        if (l == r) return tree[node];
        int mid = (l + r) / 2;

        if (idx <= mid)
            return query(2 * node + 1, l, mid, idx);
        else
            return query(2 * node + 2, mid + 1, r, idx);
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void update(int l, int r, int val) {
        updateRange(0, 0, n - 1, l, r, val);
    }

    int get(int idx) {
        return query(0, 0, n - 1, idx);
    }
};
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        SegmentTree st(n);

        for (const auto& shift : shifts) {
            int l = shift[0];
            int r = shift[1];
            int dir = shift[2];
            int val = (dir == 1) ? 1 : -1;
            st.update(l, r, val);
        }

        for (int i = 0; i < n; ++i) {
            int shift = st.get(i) % 26;
            if (shift < 0) shift += 26;
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};
