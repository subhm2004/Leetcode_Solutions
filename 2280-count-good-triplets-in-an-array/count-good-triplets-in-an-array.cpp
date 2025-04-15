class SegmentTree {
 public:
  SegmentTree(int size) : n(size) {
    tree.assign(4 * n, 0);
  }

  void update(int index, int value, int node = 1, int start = 0, int end = -1) {
    if (end == -1) end = n - 1;

    if (start == end) {
      tree[node] += value;
      return;
    }

    int mid = (start + end) / 2;
    if (index <= mid)
      update(index, value, 2 * node, start, mid);
    else
      update(index, value, 2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }

  int query(int l, int r, int node = 1, int start = 0, int end = -1) {
    if (end == -1) end = n - 1;

    if (r < start || end < l)
      return 0;
    if (l <= start && end <= r)
      return tree[node];

    int mid = (start + end) / 2;
    return query(l, r, 2 * node, start, mid) +
           query(l, r, 2 * node + 1, mid + 1, end);
  }

 private:
  int n;
  vector<int> tree;
};

class Solution {
 public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    unordered_map<int, int> numToIndex;
    for (int i = 0; i < n; ++i)
      numToIndex[nums1[i]] = i;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
      arr[i] = numToIndex[nums2[i]];

    vector<int> leftSmaller(n), rightLarger(n);
    SegmentTree leftTree(n), rightTree(n);

    for (int i = 0; i < n; ++i) {
      leftSmaller[i] = leftTree.query(0, arr[i] - 1);
      leftTree.update(arr[i], 1);
    }

    for (int i = n - 1; i >= 0; --i) {
      rightLarger[i] = rightTree.query(arr[i] + 1, n - 1);
      rightTree.update(arr[i], 1);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i)
      ans += 1LL*(leftSmaller[i]) * rightLarger[i];

    return ans;
  }
};
