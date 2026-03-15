using ll = long long;

class SegmentTree
{
private:
    static const ll MOD = 1LL * 1e9+7;

    struct Node {
        ll sum;
        ll lazy_mul;
        ll lazy_add;

        Node() {
            sum = 0;
            lazy_mul = 1;
            lazy_add = 0;
        }
    };

    vector<Node> segTree;
    int n;

    void apply(int i, int l, int r, ll mul, ll add)
    {
        ll len = (r - l + 1);

        segTree[i].sum = (segTree[i].sum * mul) % MOD;
        segTree[i].sum = (segTree[i].sum + add * len) % MOD;

        segTree[i].lazy_mul = (segTree[i].lazy_mul * mul) % MOD;
        segTree[i].lazy_add = (segTree[i].lazy_add * mul + add) % MOD;
    }

    void push(int i, int l, int r)
    {
        if (segTree[i].lazy_mul == 1 && segTree[i].lazy_add == 0)
            return;

        int mid = (l + r) / 2;

        apply(2 * i + 1, l, mid, segTree[i].lazy_mul, segTree[i].lazy_add);

        apply(2 * i + 2, mid + 1, r, segTree[i].lazy_mul, segTree[i].lazy_add);

        segTree[i].lazy_mul = 1;
        segTree[i].lazy_add = 0;
    }

    void update_Range(int i, int l, int r, int ql, int qr, ll mul, ll add)
    {
        if (r < ql || l > qr)
            return;

        if (ql <= l && r <= qr)
        {
            apply(i, l, r, mul, add);
            return;
        }

        push(i, l, r);

        int mid = (l + r) / 2;

        update_Range(2 * i + 1, l, mid, ql, qr, mul, add);
        update_Range(2 * i + 2, mid + 1, r, ql, qr, mul, add);

        segTree[i].sum = (segTree[2 * i + 1].sum + segTree[2 * i + 2].sum) % MOD;
    }

    ll query_Point(int i, int l, int r, int idx)
    {
        if (l == r)
            return segTree[i].sum % MOD;

        push(i, l, r);

        int mid = (l + r) / 2;

        if (idx <= mid)
            return query_Point(2 * i + 1, l, mid, idx);
        else
            return query_Point(2 * i + 2, mid + 1, r, idx);
    }

public:
    SegmentTree(int _n)
    {
        n = _n;
        segTree.resize(4 * n);
    }

    void update_Range(int l, int r, ll mul, ll add)
    {
        update_Range(0, 0, n - 1, l, r, mul, add);
    }

    ll query_Point(int idx)
    {
        return query_Point(0, 0, n - 1, idx);
    }
};

class Fancy {
public:
    static const int MAXN = 1e5+2;

    SegmentTree seg;
    int sz;

    Fancy() : seg(MAXN) {
        sz = 0;
    }

    void append(int val)
    {
        seg.update_Range(sz, sz, 1, val);
        sz++;
    }

    void addAll(int inc)
    {
        if (sz == 0) return;
        seg.update_Range(0, sz - 1, 1, inc);
    }

    void multAll(int m)
    {
        if (sz == 0) return;
        seg.update_Range(0, sz - 1, m, 0);
    }

    int getIndex(int idx)
    {
        if (idx >= sz) return -1;
        return (int)(seg.query_Point(idx));
    }
};
