class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int start = newInterval[0], end = newInterval[1];
        bool inserted = false;

        for (int i = 0; i < n; ++i) {
            // Case 1: current interval ends before new interval starts — no overlap
            if (intervals[i][1] < start) {
                ans.push_back(intervals[i]);
            }
            // Case 2: current interval starts after new interval ends — no overlap
            else if (intervals[i][0] > end) {
                if (!inserted) {
                    ans.push_back({start, end});
                    inserted = true;
                }
                ans.push_back(intervals[i]);
            }
            // Case 3: overlapping intervals — merge
            else {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }

        // Insert at the end if not inserted yet
        if (!inserted) {
            ans.push_back({start, end});
        }

        return ans;
    }
};
