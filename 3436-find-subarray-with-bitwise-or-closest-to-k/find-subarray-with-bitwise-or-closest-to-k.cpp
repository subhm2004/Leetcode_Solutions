class SegmentTree
{
private:
    vector<int> segTree;
    int n;

    void build(const vector<int> &arr, int i, int l, int r)
    {
        if (l == r)
        {
            segTree[i] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(arr, 2*i + 1, l, mid);
        build(arr, 2*i + 2, mid + 1, r);

        segTree[i] = segTree[2*i + 1] | segTree[2*i + 2];
    }

    int query_Range(int i, int l, int r, int ql, int qr)
    {
        if (r < ql || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return segTree[i];

        int mid = (l + r) / 2;

        return query_Range(2*i + 1, l, mid, ql, qr)
             | query_Range(2*i + 2, mid + 1, r, ql, qr);
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        segTree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    int query_Range(int l, int r)
    {
        return query_Range(0, 0, n - 1, l, r);
    }
};

class Solution {
private:
    SegmentTree* seg;
    int n;
    int k;
    
    int BS(int i) {
        int l = i;
        int h = n - 1;
        int ans = INT_MAX;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int or_val = seg->query_Range(i, mid);
            
            if (or_val < k) {
                ans = min(ans, abs(k - or_val));
                l = mid + 1;
            } else {
                ans = min(ans, abs(or_val - k));
                h = mid - 1;
            }
        }
       
        
        return ans;
    }
    
public:
    int minimumDifference(vector<int>& nums, int k) {
        this->n = nums.size();
        this->k = k;
        
        seg = new SegmentTree(nums);
        
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int result = BS(i);
            ans = min(ans, result);
            
            if (ans == 0) break;  
        }
        
        delete seg;
        return ans;
    }
};