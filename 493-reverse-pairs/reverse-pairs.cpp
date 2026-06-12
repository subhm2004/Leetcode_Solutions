using ll = long long;
// ════════════════════════════════════════════════════════════════════════════
// BIT — Point Update, Range Query
// ════════════════════════════════════════════════════════════════════════════

class BIT_PointUpdate_RangeQuery {
public:
    int n;
    vector<ll> bit;

    BIT_PointUpdate_RangeQuery(int n) {
        this->n = n;
        bit.resize(n + 1, 0);
    }

    void update(int i, ll x) {
        for (; i <= n; i += (i & -i))
            bit[i] += x;
    }

    ll prefixSum(int i) {
        ll total = 0;
        for (; i > 0; i -= (i & -i))
            total += bit[i];
        return total;
    }

    ll rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }
};
// ════════════════════════════════════════════════════════════════════════════
// COORDINATE COMPRESSION — Long Long version
// ════════════════════════════════════════════════════════════════════════════
class Coordinate_Compression_LL {
public:
    unordered_map<ll, int> compress;
    vector<ll> rev_map;

    Coordinate_Compression_LL(const vector<ll>& arr) {
        set<ll> st(arr.begin(), arr.end());
        int id = 0;
        for (ll x : st) {
            compress[x] = id;
            rev_map.push_back(x);
            id++;
        }
    }

    int size() const { return (int)rev_map.size(); }

    int count_le(ll x) const {
        return (int)(upper_bound(rev_map.begin(), rev_map.end(), x)
                     - rev_map.begin());
    }

    int bit_id(ll x) const { return compress.at(x) + 1; }

    int lower_bit_id(ll x) const {
        return (int)(lower_bound(rev_map.begin(), rev_map.end(), x)
                     - rev_map.begin()) + 1;
    }

    int upper_bit_id(ll x) const { return count_le(x); }
};



class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;

        // Pool: nums[i] aur 2*nums[i] dono — overflow safe
        vector<ll> pool;
        pool.reserve(2 * n);
        for (int x : nums) {
            pool.push_back((ll)x);
            pool.push_back(2LL * x);
        }

        Coordinate_Compression_LL cc(pool);
        BIT_PointUpdate_RangeQuery bit(cc.size());

        ll pairs = 0;

        for (int j = 0; j < n; ++j) {
            ll threshold = 2LL * nums[j];

            // Query: kitne already-inserted values strictly > threshold?
            int seen       = (int)bit.prefixSum(cc.size());
            int notGreater = (int)bit.prefixSum(cc.upper_bit_id(threshold));
            pairs += seen - notGreater;

            // Insert: nums[j] BIT mein daalo
            bit.update(cc.bit_id((ll)nums[j]), 1);
        }

        return (int)pairs;
    }
};

