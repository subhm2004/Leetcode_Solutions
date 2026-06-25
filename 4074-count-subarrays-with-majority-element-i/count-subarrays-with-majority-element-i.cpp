class FenwickTree {
public:
    int n;
    vector<int> bit; // 1-indexed fenwick array

    FenwickTree(int n) {
        this->n = n;
        bit.resize(n + 1, 0);
    }

    void update(int i, int x) {
        for (; i <= n; i += (i & -i))
            bit[i] += x;
    }

    int sum(int i) {
        int total = 0;
        for (; i > 0; i -= (i & -i))
            total += bit[i];
        return total;
    }
    int range_sum(int l, int r) { return sum(r) - sum(l - 1); }
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

    vector<int> get_compressed(const vector<int>& arr) const {
        vector<int> res(arr.size());
        for (int i = 0; i < (int)arr.size(); i++)
            res[i] = compress.at(arr[i]);
        return res;
    }

    int get_original(int val) const { return rev_map[val]; }

    int size() const { return (int)rev_map.size(); }
};

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                prefix[i + 1] = prefix[i] + 1;
            else
                prefix[i + 1] = prefix[i] - 1;
        }

        Coordinate_Compression cc(prefix);
        vector<int> compressed = cc.get_compressed(prefix);

        FenwickTree bit(cc.size());

        long long ans = 0;

        for (int x : compressed) {
            ans += bit.sum(x);
            bit.update(x + 1, 1);
        }

        return ans;
    }
};
