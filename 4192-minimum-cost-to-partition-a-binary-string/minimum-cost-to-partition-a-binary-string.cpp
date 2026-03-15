class Solution {
public:
    long long encCost, flatCost;
    vector<int> pref;

    int count_sensitive(int l, int r) { return pref[r + 1] - pref[l]; }

    long long solve(int l, int r) {

        int L = r - l + 1;
        int X = count_sensitive(l, r);

        long long cost;

        if (X == 0)
            cost = flatCost;
        else
            cost = 1LL * L * X * encCost;

        if (L % 2 == 0) {

            int mid = (l + r) / 2;

            long long split = solve(l, mid) + solve(mid + 1, r);

            cost = min(cost, split);
        }

        return cost;
    }

    long long minCost(string s, int encCost, int flatCost) {

        this->encCost = encCost;
        this->flatCost = flatCost;

        int n = s.size();

        pref.resize(n + 1);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + (s[i] == '1');

        return solve(0, n - 1);
    }
};