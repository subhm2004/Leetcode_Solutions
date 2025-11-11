#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> BIT;
    int len;
public:
    FenwickTree(int size) {
        len = size;
        BIT.assign(size + 2, 0);
    }

    void mark(int idx, int val) {
        idx++;
        while (idx <= len) {
            BIT[idx] += val;
            idx += (idx & -idx);
        }
    }

    int sum(int idx) {
        idx++;
        int res = 0;
        while (idx > 0) {
            res += BIT[idx];
            idx -= (idx & -idx);
        }
        return res;
    }

    int rangeCount(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

class Solution {
    void groupIdx(vector<vector<int>>& groups, const vector<int>& vals) {
        int n = vals.size();
        for (int pos = 0; pos < n; pos++) {
            if (vals[pos] > 0) {
                groups[vals[pos]].push_back(pos);
            }
        }
    }

    int countOperations(const vector<int>& positions, FenwickTree& tracker) {
        int ops = 0;
        int lastPos = -2;
        for (int curr : positions) {
            if (lastPos == -2 || tracker.rangeCount(lastPos + 1, curr - 1) > 0) {
                ops++;
            }
            lastPos = curr;
        }
        for (int pos : positions) {
            tracker.mark(pos, 1);
        }
        return ops;
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int peak = *max_element(nums.begin(), nums.end());

        vector<vector<int>> groups(peak + 6);
        groupIdx(groups, nums);

        FenwickTree zeroTracker(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zeroTracker.mark(i, 1);
        }

        int res = 0;
        for (int val = 1; val <= peak; val++) {
            if (!groups[val].empty()) {
                res += countOperations(groups[val], zeroTracker);
            }
        }
        return res;
    }
};

