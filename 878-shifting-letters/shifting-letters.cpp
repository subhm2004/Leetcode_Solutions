// class Solution {
// public:
//     string shiftingLetters(string s, vector<int>& shifts) {
//         // Step 1: Right se left cumulative shifts calculate karo (SUFFIX SUM)
//         for (int i = shifts.size() - 2; i >= 0; --i) 
//             shifts[i] = (shifts[i] + shifts[i + 1]) % 26;  // Mod 26 le rahe hain taaki letters loop ho sake
        
//         // Step 2: Har character ko shift karo
//         for (int i = 0; i < s.length(); ++i) 
//             s[i] = 'a' + (s[i] - 'a' + shifts[i]) % 26;  // Character ko number me convert karke shift karke wapas char banao
        
//         return s; // Final shifted string return karo
//     }
// };

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l] % 26;
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * node + 1, l, mid);
        build(arr, 2 * node + 2, mid + 1, r);
        tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % 26;
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0; // No overlap
        if (ql <= l && r <= qr) return tree[node]; // Complete overlap

        int mid = (l + r) / 2;
        int left = query(2 * node + 1, l, mid, ql, qr);
        int right = query(2 * node + 2, mid + 1, r, ql, qr);
        return (left + right) % 26;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    int getSuffixSum(int l) {
        return query(0, 0, n - 1, l, n - 1);
    }
};
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        SegmentTree st(shifts);
        for (int i = 0; i < s.size(); ++i) {
            int shift = st.getSuffixSum(i);
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return s;
    }
};
