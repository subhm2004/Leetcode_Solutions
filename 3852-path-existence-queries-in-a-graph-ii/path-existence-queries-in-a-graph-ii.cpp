class BinaryLifting {
private:
    int n, LOG;
    vector<vector<int>> up;

public:
    BinaryLifting(vector<int>& farthest) {
        n = farthest.size();
        LOG = log2(n) + 1;

        up.assign(n, vector<int>(LOG));

        for (int i = 0; i < n; i++)
            up[i][0] = farthest[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    int minJumps(int l, int r) {
        if (l >= r)
            return 0;

        int cur = l;
        int ans = 0;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[cur][j] < r) {
                cur = up[cur][j];
                ans += (1 << j);
            }
        }

        if (up[cur][0] >= r)
            return ans + 1;

        return -1;
    }
};

class Solution {
public:
    int customUpperBound(vector<pair<int, int>>& arr, int target) {
        int l = 0;
        int r = arr.size() - 1;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid].first <= target) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> nodeToIdx(n);

        for (int i = 0; i < n; i++)
            nodeToIdx[arr[i].second] = i;

        vector<int> farthest(n);

        for (int i = 0; i < n; i++) {
            farthest[i] = customUpperBound(arr, arr[i].first + maxDiff);
        }

        BinaryLifting bl(farthest);

        vector<int> ans;

        for (auto &q : queries) {

            int a = nodeToIdx[q[0]];
            int b = nodeToIdx[q[1]];

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            if (a > b)
                swap(a, b);

            ans.push_back(bl.minJumps(a, b));
        }

        return ans;
    }
};