// minimum deletions = length - longest alternating subsequence
using ll = long long;
class SegmentTree
{
private:
    vector<ll> segTree;
    int n;

    void build(const vector<int> &arr, int i, int l, int r)
    {
        if (l == r)
        {
            segTree[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * i + 1, l, mid);
        build(arr, 2 * i + 2, mid + 1, r);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    void update_Point(int i, int l, int r, int idx, int val)
    {
        if (l == r)
        {
            segTree[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update_Point(2 * i + 1, l, mid, idx, val);
        else
            update_Point(2 * i + 2, mid + 1, r, idx, val);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    ll query_Range(int i, int l, int r, int start, int end)
    {
        if (r < start || l > end)
            return 0;
        if (start <= l && r <= end)
            return segTree[i];
        int mid = (l + r) / 2;
        return query_Range(2 * i + 1, l, mid, start, end) + query_Range(2 * i + 2, mid + 1, r, start, end);
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        segTree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    void update_Point(int idx, int val) { update_Point(0, 0, n - 1, idx, val); }
    ll query_Range(int l, int r) { return query_Range(0, 0, n - 1, l, r); }
}; 

class Solution {
public:

    vector<int> minDeletions(string s, vector<vector<int>>& queries) {

        int n = s.size();

        // helper_arr array
        vector<int> helper_arr(n, 0);

        for(int i = 1; i < n; i++)
            helper_arr[i] = (s[i] != s[i-1]);

        SegmentTree st(helper_arr);

        vector<int> ans;

        for(auto &q : queries) {

            // type 1 : flip
            if(q[0] == 1) {

                int j = q[1];

                // flip
                s[j] = (s[j] == 'A' ? 'B' : 'A');

                // update helper_arr[j]
                if(j - 1 >= 0) {
                    int new_val = (s[j] != s[j-1]);
                    helper_arr[j] = new_val;
                    st.update_Point(j, new_val);
                }

                // update helper_arr[j+1]
                if(j + 1 < n) {
                    int new_val = (s[j+1] != s[j]);
                    helper_arr[j+1] = new_val;
                    st.update_Point(j + 1, new_val);
                }
            }

            // type 2 : query
            else {

                int l = q[1];
                int r = q[2];

                if(l == r) {
                    ans.push_back(0);
                    continue;
                }

                ll runs = 1 + st.query_Range(l + 1, r);

                int len = r - l + 1;

                ans.push_back(len - runs);
            }
        }

        return ans;
    }
};
