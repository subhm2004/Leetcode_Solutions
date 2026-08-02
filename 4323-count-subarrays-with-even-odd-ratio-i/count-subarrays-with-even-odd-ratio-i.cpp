using ll = long long;

class Coordinate_Compression {
public:
    unordered_map<ll, int> compress;
    vector<ll> rev_map;

    Coordinate_Compression(const vector<ll>& arr) {
        set<ll> st(arr.begin(), arr.end());
        int id = 0;
        for (ll x : st) {
            compress[x] = id;
            rev_map.push_back(x);
            id++;
        }
    }

    vector<int> get_compressed(const vector<ll>& arr) const {
        vector<int> res(arr.size());
        for (int i = 0; i < (int)arr.size(); i++)
            res[i] = compress.at(arr[i]);
        return res;
    }

    ll get_original(int val) const { return rev_map[val]; }

};

// Point Update Range Query
class BIT {
public:
    int n;
    vector<ll> bit;

    BIT(int n) {
        this->n = n;
        bit.resize(n + 1, 0);
    }

    void update(int i, ll x) {
        for (; i <= n; i += (i & -i))
            bit[i] += x;
    }
    // sum from [0...i]
    ll prefix_sum(int i) {
        ll total = 0;
        for (; i > 0; i -= (i & -i))
            total += bit[i];
        return total;
    }
    // sum from [l...r]
    ll range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

/*
 * count_Non_Strict_Inversions(arr)
 * ───────────────────────────────
 * Pairs (i < j) count karta hai jahan arr[i] >= arr[j]
 *
 * NOTE: STRICT version (arr[i] > arr[j]) chahiye ho toh prefix_sum(idx) kar dete hai 
 lekin yha pr hume (arr[i] >= arr[j]) chahiye to hum prefix_sum(idx-1) kr denge
  */
ll count_Non_Strict_Inversions(const vector<ll>& arr) {
    int n = (int)arr.size();
    Coordinate_Compression cc(arr);
    vector<int> comp = cc.get_compressed(arr);
    int m = comp.size();
    BIT bit(m);

    ll count = 0;
    for (int i = 0; i < n; i++) {
        int idx = comp[i] + 1;                  // 1-indexed BIT position
        count += (ll)bit.prefix_sum(m) - bit.prefix_sum(idx - 1); // NON-STRICT (>=)
        bit.update(idx, 1);
    }
    return count;
}

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        // ── Step 1: condition transform ──
        // x/y <= a/b  →  x*b <= y*a  →  b*x - a*y <= 0
        // weight: even -> +b,  odd -> -a
        vector<ll> S(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ll w = (nums[i] % 2 == 0) ? (ll)b : -(ll)a;
            S[i + 1] = S[i] + w;
        }

        // ── Step 2 + 3: prefix array pe non-strict inversions ──
        // subarray [l..r] valid ⟺ S[r] - S[l-1] <= 0 ⟺ S[l-1] >= S[r]
        return (int)count_Non_Strict_Inversions(S);
    }
};