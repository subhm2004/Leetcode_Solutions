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

    int size() const { return (int)rev_map.size(); }

    int count_le(ll x) const {
        return (int)(upper_bound(rev_map.begin(), rev_map.end(), x)
                     - rev_map.begin());
    }

    int bit_id(ll x) const { return compress.at(x) + 1; }
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
 * count_NonStrict_Inversions(arr)
 * ───────────────────────────────
 * Pairs (i < j) count karta hai jahan arr[i] >= arr[j]
 *
 *   1) compress karo — values 1e14 tak, BIT index chhota chahiye
 *   2) left→right chalo, har element pe:
 *        i                     = ab tak kitne insert hue (total seen)
 *        prefix_sum(idx - 1)   = ab tak kitne STRICTLY CHHOTE hain
 *        farak                 = kitne >= current hain  ✔
 *   3) phir current ko BIT me daal do
 *
 * NOTE: STRICT version (arr[i] > arr[j]) chahiye ho toh
 *       prefix_sum(idx) kar dena — bas ek character ka farak.
 */
ll count_NonStrict_Inversions(const vector<ll>& arr) {
    int n = (int)arr.size();
    Coordinate_Compression cc(arr);
    vector<int> comp = cc.get_compressed(arr);
    int m = comp.size();
    BIT bit(m);

    ll count = 0;
    for (int i = 0; i < n; i++) {
        int idx = comp[i] + 1;                  // 1-indexed BIT position
        count += (ll)bit.prefix_sum(m) - bit.prefix_sum(idx - 1); // NON-STRICT (>=)
        // count += (ll)bit.prefix_sum(m) - bit.prefix_sum(idx); //  STRICT   (>)
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
        return (int)count_NonStrict_Inversions(S);
    }
};