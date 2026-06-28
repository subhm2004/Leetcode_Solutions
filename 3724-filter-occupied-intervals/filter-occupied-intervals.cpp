class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int free_start, int free_end) {
        // Step 1: Sort intervals by start time
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Step 2: Merge overlapping AND touching intervals
        // jo current chal rahe merged interval ko track karta hai
        vector<vector<int>> merged;
        int curr_Start = -1, curr_end = -1; 
        bool has_current = false; // abhi tak koi interval track ho raha hai ya nahi

        for (auto &interval : occupiedIntervals) {
            int start = interval[0], end = interval[1];

            if (has_current == false) {
                // Pehla interval, naya current set karo
                curr_Start = start;
                curr_end = end;
                has_current = true;
            } 
            else if (start <= curr_end + 1) {
                // Overlap ya touch ho raha hai current ke saath
                // curr_end ko update kar do (max le lo)
                if (end > curr_end) curr_end = end;
            } 
            else {
                // Naya interval purane se overlap nahi karta
                // pehle wala current ko ans mein daal do
                merged.push_back({curr_Start, curr_end});
                // ab naya current shuru karo
                curr_Start = start;
                curr_end = end;
            }
        }

        // Last pending current interval ko bhi push kar do
        if (has_current) {
            merged.push_back({curr_Start, curr_end});
        }

        // Step 3: Free interval [free_start, free_end] ko exclude karte hai
        vector<vector<int>> ans;
        for (auto &interval : merged) {
            int start = interval[0], end = interval[1];

            // Case 1: Free interval poori tarah bahar hai , as it is rakho 
            if (free_end < start || free_start > end) {
                ans.push_back({start, end});
                continue;
            }

            // Case 2: Interval ka left part bacha hai (free se pehle)
            if (start < free_start) {
                ans.push_back({start, free_start - 1});
            }

            // Case 3: Interval ka right part bacha hai (free ke baad)
            if (end > free_end) {
                ans.push_back({free_end + 1, end});
            }

            // Agar interval poori tarah free ke andar hai, to kuch push nahi hoga
        }

        return ans;
    }
};