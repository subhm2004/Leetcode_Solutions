class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            while (!pq.empty() && pq.top() < start) {
                pq.pop();
            }

            ans += pq.size();

            pq.push(end);
        }

        return ans;
    }
};