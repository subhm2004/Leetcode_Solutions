class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;

        int sr = startPos[0];
        int sc = startPos[1];

        int hr = homePos[0];
        int hc = homePos[1];

        //  Row Cost 
        if (sr < hr) {
            // neeche jaana hai
            for (int r = sr + 1; r <= hr; r++)
                ans += rowCosts[r];
        } else {
            // upar jaana hai
            for (int r = sr - 1; r >= hr; r--)
                ans += rowCosts[r];
        }

        // Col Cost 
        if (sc < hc) {
            // right jaana hai
            for (int c = sc + 1; c <= hc; c++)
                ans += colCosts[c];
        } else {
            // left jaana hai
            for (int c = sc - 1; c >= hc; c--)
                ans += colCosts[c];
        }

        return ans;
    }
};