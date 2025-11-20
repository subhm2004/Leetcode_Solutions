class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        
        // Sort by right end increasing; if tie, left end decreasing
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if (a[1] == b[1]) return a[0] > b[0];
                 return a[1] < b[1];
             });

        int n = intervals.size();
        int count = 2;

        // Pick two smallest points in the first interval
        int b = intervals[0][1];
        int a = b - 1;

        for (int i = 1; i < n; i++) {
            int L = intervals[i][0];
            int R = intervals[i][1];

            // Already has 2 required points
            if (a >= L) continue;

            // Has only 1 point inside
            if (b >= L) {
                count += 1;
                a = b;
                b = R;
            }
            // No points inside → add 2 points R-1 and R
            else {
                count += 2;
                a = R - 1;
                b = R;
            }
        }

        return count;
    }
};
