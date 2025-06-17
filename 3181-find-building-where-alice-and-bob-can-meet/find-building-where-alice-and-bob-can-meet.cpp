class SegmentTree {
private:
    vector<int> tree;
    vector<int>* heights;
    int n;

    void build(int i, int l, int r) {
        if (l == r) {
            tree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid);
        build(2 * i + 2, mid + 1, r);

        int leftIdx = tree[2 * i + 1];
        int rightIdx = tree[2 * i + 2];
        tree[i] = ((*heights)[leftIdx] >= (*heights)[rightIdx]) ? leftIdx : rightIdx;
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return -1;
        if (ql <= l && r <= qr) return tree[i];

        int mid = l + (r - l) / 2;
        int left = query(2 * i + 1, l, mid, ql, qr);
        int right = query(2 * i + 2, mid + 1, r, ql, qr);

        if (left == -1) return right;
        if (right == -1) return left;
        return ((*heights)[left] >= (*heights)[right]) ? left : right;
    }

public:
    SegmentTree(vector<int>& h) {
        heights = &h;
        n = h.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    // Public query function
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SegmentTree seg(heights);

        vector<int> ans;
        for (auto& query : queries) {
            int alice = min(query[0], query[1]);
            int bob = max(query[0], query[1]);

            if (alice == bob || heights[bob] > heights[alice]) {
                ans.push_back(bob);
                continue;
            }

            int l = bob + 1, r = n - 1;
            int ans_idx = INT_MAX;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int idx = seg.query(l, mid);

                if (heights[idx] > max(heights[alice], heights[bob])) {
                    ans_idx = min(ans_idx, idx);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            ans.push_back(ans_idx == INT_MAX ? -1 : ans_idx);
        }

        return ans;
    }
};
