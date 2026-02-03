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

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();

        Coordinate_Compression cc(nums);

        int K = cc.rev_map.size();

        BIT bit1(K), bit2(K);

        vector<int> arr1, arr2;

        arr1.push_back(nums[0]);
        bit1.update(cc.compress[nums[0]] + 1, 1);

        arr2.push_back(nums[1]);
        bit2.update(cc.compress[nums[1]] + 1, 1);

        int size1 = 1, size2 = 1;

        for (int i = 2; i < n; i++)
        {
            int x = nums[i];

            int pos = upper_bound(cc.rev_map.begin(),
                                   cc.rev_map.end(),
                                   x) - cc.rev_map.begin();

            ll len1 = bit1.sum(pos);
            ll len2 = bit2.sum(pos);

            ll g1 = size1 - len1;
            ll g2 = size2 - len2;

            int id = cc.compress[x] + 1;

            if (g1 > g2)
            {
                arr1.push_back(x);
                bit1.update(id, 1);
                size1++;
            }
            else if (g1 < g2)
            {
                arr2.push_back(x);
                bit2.update(id, 1);
                size2++;
            }
            else
            {
                if (size1 < size2)
                {
                    arr1.push_back(x);
                    bit1.update(id, 1);
                    size1++;
                }
                else if (size2 < size1)
                {
                    arr2.push_back(x);
                    bit2.update(id, 1);
                    size2++;
                }
                else
                {
                    arr1.push_back(x);
                    bit1.update(id, 1);
                    size1++;
                }
            }
        }

        vector<int> ans;
        for (int v : arr1)
            ans.push_back(v);
        for (int v : arr2)
            ans.push_back(v);

        return ans;
    }
};

