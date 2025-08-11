const int MOD = 1e9 + 7;
class SegmentTree {
private:
    vector<long long> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start] % MOD;
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = (tree[2 * node + 1] * tree[2 * node + 2]) % MOD;
        }
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 1;  
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        long long left_product = query(2 * node + 1, start, mid, l, r);
        long long right_product = query(2 * node + 2, mid + 1, end, l, r);
        return (left_product * right_product) % MOD;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    long long range_query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

class Solution {
public:
     vector<int> extract_powers_of_2(int n) {
        vector<int> powers;
        for (int bit = 0; n > 0; ++bit, n >>= 1) {
            if (n & 1) powers.push_back(1 << bit);
        }
        return powers;
    }
    vector<int> extract_powers_of_2_easy(int n) {
    vector<int> powers;
    int power = 0;
    
    while (n > 0) {
        if (n % 2 == 1) {  // If last digit is 1
            powers.push_back(pow(2, power));
        }
        n = n / 2;  // Remove last digit
        power++;
    }
    return powers;
}
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // vector<int> powers = extract_powers_of_2(n);
        vector<int> powers = extract_powers_of_2_easy(n);


        SegmentTree segTree(powers);

        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back((int)segTree.range_query(q[0], q[1]));
        }
        return ans;
    }
};

