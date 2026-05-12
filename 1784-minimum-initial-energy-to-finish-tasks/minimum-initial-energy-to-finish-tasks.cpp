class Solution {
public:
    bool is_possible(vector<vector<int>>& tasks, int mid) {
        for (auto& task : tasks) {

            int actual = task[0];
            int minimum = task[1];

            if (minimum > mid) {
                return false;
            }

            mid -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        int l = 0;
        int r = 1e9;

        int ans = INT_MAX;

        sort(tasks.begin(), tasks.end(), [](auto& task1, auto& task2) {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        });

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (is_possible(tasks, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};