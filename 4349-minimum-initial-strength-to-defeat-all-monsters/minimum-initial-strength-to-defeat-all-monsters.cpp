using ll = long long;
class Solution {
public:
    vector<ll> build_diff_array(int n, vector<vector<int>>& boosts) {

        vector<ll> diff(n + 1, 0);

        for (auto &boost : boosts) {
            int l = boost[0];
            int r = boost[1];
            ll val = boost[2];

            diff[l] += val;

            if (r + 1 < n)
                diff[r + 1] -= val;
        }

        for (int i = 1; i < n; i++)
            diff[i] += diff[i - 1];

        return diff;
    }

    bool can_defeat(ll strength, vector<int>& monsters, vector<ll>& diff) {

        ll curr = strength;

        for (int i = 0; i < monsters.size(); i++) {

            if (curr + diff[i] < monsters[i])
                return false;

            curr = max(0LL, curr - 1LL * monsters[i]);
        }

        return true;
    }

    ll binary_search(vector<int>& monsters, vector<ll>& diff) {

        ll low = 0;
        ll high = 0;

        for (int x : monsters)
            high += x;

        ll ans = high;

        while (low <= high) {

            ll mid = low + (high - low) / 2;

            if (can_defeat(mid, monsters, diff)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {

        vector<ll> diff = build_diff_array(monsters.size(), boosts);

        return binary_search(monsters, diff);
    }
};