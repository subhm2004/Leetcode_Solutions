using ll = long long;

class BIT {
public:
    int n;
    vector<ll> bit;

    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, ll val) {
        for (; i <= n; i += (i & -i))
            bit[i] += val;
    }

    ll sum(int i) {
        ll ans = 0;
        for (; i > 0; i -= (i & -i))
            ans += bit[i];
        return ans;
    }
};

class Coordinate_Compression {
public:
    unordered_map<int, int> compress;
    vector<int> rev_map;

    Coordinate_Compression(const vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        int id = 0;
        for (int x : st) {
            compress[x] = id;
            rev_map.push_back(x);
            id++;
        }
    }

    vector<int> get_compressed(const vector<int>& arr) {
        vector<int> res(arr.size());
        for (int i = 0; i < (int)arr.size(); i++)
            res[i] = compress[arr[i]];
        return res;
    }

    int get_original(int idx) {
        return rev_map[idx];
    }
};

ll get_K_Smallest_Sum(
    int need,
    BIT& count_BIT,
    BIT& sum_BIT,
    Coordinate_Compression& cc
) {
    int pos = 0;
    ll ans = 0;
    int rem = need;

    for (int pw = 1 << 17; pw; pw >>= 1) {
        if (pos + pw <= count_BIT.n &&
            count_BIT.bit[pos + pw] < rem) {

            rem -= count_BIT.bit[pos + pw];
            ans += sum_BIT.bit[pos + pw];
            pos += pw;
        }
    }

    if (rem > 0)
        ans += (ll)rem * cc.get_original(pos);

    return ans;
}

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        ll ans = nums[0];

        if (k == 1) return ans;

        vector<int> arr(nums.begin() + 1, nums.end());

        Coordinate_Compression cc(arr);
        vector<int> comp = cc.get_compressed(arr);

        int M = cc.rev_map.size();

        BIT count_BIT(M), sum_BIT(M);

        int window_start = 0;
        int window_end = min((int)arr.size() - 1, dist);

        for (int i = window_start; i <= window_end; i++) {
            int rank = comp[i] + 1;
            count_BIT.update(rank, 1);
            sum_BIT.update(rank, arr[i]);
        }

        ll result = get_K_Smallest_Sum(k - 1, count_BIT, sum_BIT, cc);

        while (window_end + 1 < (int)arr.size()) {

            count_BIT.update(comp[window_start] + 1, -1);
            sum_BIT.update(comp[window_start] + 1, -arr[window_start]);
            window_start++;

            window_end++;
            count_BIT.update(comp[window_end] + 1, 1);
            sum_BIT.update(comp[window_end] + 1, arr[window_end]);

            result = min(result, get_K_Smallest_Sum(k - 1, count_BIT, sum_BIT, cc));
        }

        return ans + result;
    }
};
