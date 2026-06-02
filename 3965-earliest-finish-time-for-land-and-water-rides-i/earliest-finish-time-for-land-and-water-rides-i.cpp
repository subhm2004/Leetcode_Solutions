class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
                           vector<int>& wd) {
        int mini = INT_MAX;
        for (int i = 0; i < ls.size(); i++) {
            int land_end = ls[i] + ld[i];

            for (int j = 0; j < ws.size(); j++) {
                int water_start = max(land_end, ws[j]);
                int final_time = water_start + wd[j];
                mini = min(mini, final_time);
            }
        }
        for (int i = 0; i < ws.size(); i++) {
            int water_end = ws[i] + wd[i];

            for (int j = 0; j < ls.size(); j++) {
                int lnd_strt = max(water_end, ls[j]);
                int f_time = lnd_strt + ld[j];
                mini = min(mini, f_time);
            }
        }
        return mini;
    }
};