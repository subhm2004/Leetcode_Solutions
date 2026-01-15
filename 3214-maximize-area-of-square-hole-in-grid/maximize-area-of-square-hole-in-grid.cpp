class Solution {
public:
    int max_gap(vector<int>& bars) {
        if (bars.empty()) return 1; // no removal → gap = 1
        
        sort(bars.begin(), bars.end());

        int max_streak = 1;
        int curr_streak = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i-1] + 1) {
                curr_streak++;
            } else {
                max_streak = max(max_streak, curr_streak + 1);
                curr_streak = 1;
            }
        }
        max_streak = max(max_streak, curr_streak + 1);

        return max_streak;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hGap = max_gap(hBars);
        int vGap = max_gap(vBars);

        int side = min(hGap, vGap);
        return side * side;
    }
};
