class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;
        for (auto &task : tasks) {
            int finish_time = task[0] + task[1]; // si + ti
            ans = min(ans, finish_time);
        }
        return ans;
    }
};