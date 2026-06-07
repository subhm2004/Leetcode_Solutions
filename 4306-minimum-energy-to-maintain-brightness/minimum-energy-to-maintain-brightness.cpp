class Solution {
public:
    long long minEnergy(int n, int brightness,
                             vector<vector<int>>& intervals) {

        // ─────────────────────────────────────────────
        // STEP 1: Sort intervals by start time
        // Merging ke liye pehle sort karna zaroori hai
        // ─────────────────────────────────────────────
        sort(intervals.begin(), intervals.end());

        long long totalTime = 0;

        // Pehle interval se merging shuru karo
        long long start = intervals[0][0];
        long long end   = intervals[0][1];

        // ─────────────────────────────────────────────
        // STEP 2: Merge overlapping/adjacent intervals
        // Taaki total active time units count kar sakein
        // ─────────────────────────────────────────────
        for (int i = 1; i < intervals.size(); i++) {

            long long l = intervals[i][0]; // current interval ka start
            long long r = intervals[i][1]; // current interval ka end

            if (l <= end + 1) {
                // Overlap ya adjacent hai → merge karo
                // Example: [1,3] and [2,5] → [1,5]
                // Example: [1,3] and [4,6] → [1,6]  (adjacent, +1 trick)
                end = max(end, r);

            } else {
                // Gap aa gaya → pichla interval complete hua
                // Uski length totalTime mein add karo
                totalTime += end - start + 1;

                // Naya interval shuru karo
                start = l;
                end   = r;
            }
        }

        // Loop ke baad last interval abhi bhi pending hai → add karo
        totalTime += end - start + 1;

        // ─────────────────────────────────────────────
        // STEP 3: Minimum bulbs calculate karo
        //
        // Ek bulb maximum 3 positions illuminate karta hai:
        //   left neighbour + itself + right neighbour
        //
        // To cover 'brightness' positions:
        //   bulbs = ceil(brightness / 3)
        //
        // Integer ceil trick:
        //   ceil(a / b) = (a + b - 1) / b
        //   ceil(brightness / 3) = (brightness + 2) / 3
        // ─────────────────────────────────────────────
        long long bulbs = (brightness + 2) / 3;

        // ─────────────────────────────────────────────
        // STEP 4: Total energy = bulbs × totalTime
        //
        // Har active time unit pe 'bulbs' number of
        // bulbs ON rehte hain, each consuming 1 energy
        // ─────────────────────────────────────────────
        return bulbs * totalTime;
    }
};