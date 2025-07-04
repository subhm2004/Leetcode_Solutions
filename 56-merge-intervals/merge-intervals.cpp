class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            // Case 1: No Overlap
            if (intervals[i][0] > end) {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } 
            // Case 2: Overlap
            else {
                end = max(end, intervals[i][1]);
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};