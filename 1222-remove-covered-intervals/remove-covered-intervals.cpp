class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Step 1: Sort karo start se, aur agar same ho to end descending me
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1]; // start same ho to bada end pehle
            return a[0] < b[0];     // start chhota ho to pehle
        });

        int count = 0;
        int max_end = 0; // ab tak ka max end

        // Step 2: Traverse karo
        for (auto& interval : intervals) {
            int curr_end = interval[1];
            if (curr_end > max_end) {
                count++;            // not covered
                max_end = curr_end;  // update max end
            }
            // else covered hai, skip
        }

        return count;
    }
};
