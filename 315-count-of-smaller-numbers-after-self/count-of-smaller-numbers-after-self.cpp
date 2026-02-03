using ll = long long;
class Coordinate_Compression
{
public:
    unordered_map<int, int> compress; // original value -> compressed value
    vector<int> rev_map;              // compressed value -> original value

    Coordinate_Compression(const vector<int> &arr)
    {
        set<int> st(arr.begin(), arr.end()); // unique & sorted
        int id = 0;
        for (int x : st)
        {
            compress[x] = id; // 0-based
            rev_map.push_back(x);
            id++;
        }
    }

    vector<int> get_compressed(const vector<int> &arr)
    {
        vector<int> res(arr.size());
        for (int i = 0; i < (int)arr.size(); i++)
            res[i] = compress[arr[i]];
        return res;
    }

    int get_original(int val)
    {
        return rev_map[val];
    }
};

class BIT
{
public:
    int n;
    vector<ll> bit;

    BIT(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, ll x)
    {
        for (; i <= n; i += (i & -i))
            bit[i] += x;
    }

    ll  sum(int i)
    {
        ll total = 0;
        for (; i > 0; i -= (i & -i))
            total += bit[i];
        return total;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        Coordinate_Compression cc(nums);
        int K = cc.rev_map.size();

        BIT bit(K);

        vector<int> ans(n, 0);

        // traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            int id = cc.compress[nums[i]];   // 0-based

            // strictly smaller => indices [0 ... id-1]
            ans[i] = bit.sum(id);

            // insert current number
            bit.update(id + 1, 1);
        }

        return ans;
    }
};
