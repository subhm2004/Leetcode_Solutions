class Solution {
    struct State {
        long long sum;
        int l;
        int r;
        long long valL;
        long long valR;

        bool operator>(const State& other) const {
            if (sum != other.sum) return sum > other.sum;
            return l > other.l;
        }
    };

public:
    int minimumPairRemoval(vector<int>& nums_in) {
        int n = nums_in.size();
        if (n < 2) return 0;

        vector<long long> nums(n);
        vector<int> L(n), R(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = nums_in[i];
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[n - 1] = -1;

        auto isInv = [&](int i, int j) {
            if (i < 0 || j < 0) return 0;
            return nums[i] > nums[j] ? 1 : 0;
        };

        int invCount = 0;
        priority_queue<State, vector<State>, greater<State>> pq;

        for (int i = 0; i < n - 1; ++i) {
            invCount += isInv(i, i + 1);
            pq.push({nums[i] + nums[i + 1], i, i + 1, nums[i], nums[i + 1]});
        }

        int operations = 0;

        while (invCount > 0 && !pq.empty()) {
            State top = pq.top();
            pq.pop();

            int i = top.l;
            int j = top.r;

            if (i < 0 || j < 0 || R[i] != j || L[j] != i ||
                nums[i] != top.valL || nums[j] != top.valR) {
                continue;
            }

            int pre = L[i];
            int nxt = R[j];

            invCount -= isInv(pre, i);
            invCount -= isInv(i, j);
            invCount -= isInv(j, nxt);

            nums[i] = top.sum;
            R[i] = nxt;
            if (nxt != -1) L[nxt] = i;

            L[j] = -1;
            R[j] = -1;
            operations++;

            invCount += isInv(pre, i);
            invCount += isInv(i, nxt);

            if (pre != -1) pq.push({nums[pre] + nums[i], pre, i, nums[pre], nums[i]});
            if (nxt != -1) pq.push({nums[i] + nums[nxt], i, nxt, nums[i], nums[nxt]});
        }

        return operations;
    }
};
