class Solution {
public:
    bool canDistribute(int idx, const vector<int>& jobs, int k, int limit, vector<int>& workers) {
        if (idx == jobs.size()) {
            return true;
        }

        for (int i = 0; i < k; ++i) {
            if (workers[i] + jobs[idx] <= limit) {
                workers[i] += jobs[idx];

                if (canDistribute(idx + 1, jobs, k, limit, workers)) {
                    return true;
                }

                workers[i] -= jobs[idx];

                if (workers[i] == 0) {
                    break;
                }
            }
        }

        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        int low = *max_element(jobs.begin(), jobs.end());
        int high = accumulate(jobs.begin(), jobs.end(), 0);
        int ans = high;

        while (low < high) {
            int mid = low + (high - low) / 2;
            vector<int> workers(k, 0);

            if (canDistribute(0, jobs, k, mid, workers)) {
                ans = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
