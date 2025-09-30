class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);  // initially sabko -1 se bhar do

        // Outer loop → har interval ke liye
        for(int i = 0; i < n; i++) {
            int end_val = intervals[i][1];   // current interval ka END
            int min_start = INT_MAX;         // best candidate ka start
            int idx = -1;                   // best candidate ka index

            // Inner loop → sab intervals check karo
            for(int j = 0; j < n; j++) {
                // Agar start[j] ≥ end[i] hai to ye candidate ban sakta hai
                if(intervals[j][0] >= end_val) {
                    // Dekho kya ye ab tak ka sabse chhota start hai?
                    if(intervals[j][0] < min_start) {
                        min_start = intervals[j][0];
                        idx = j;
                    }
                }
            }

            ans[i] = idx;  // jo best mila uska index store karo
        }

        return ans;
    }
};