class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if (n <= 1) return 0;

        sort(stockPrices.begin(), stockPrices.end());

        int lines = 1; 
        
        for (int i = 1; i < n - 1; ++i) {
            long long x1 = stockPrices[i - 1][0], y1 = stockPrices[i - 1][1];
            long long x2 = stockPrices[i][0],     y2 = stockPrices[i][1];
            long long x3 = stockPrices[i + 1][0], y3 = stockPrices[i + 1][1];

            long long dy1 = y2 - y1;
            long long dx1 = x2 - x1;
            long long dy2 = y3 - y2; 
            long long dx2 = x3 - x2;

            // slop different hote hi lines badal jayegi 
            if (dy1 * dx2 != dy2 * dx1) {
                ++lines;
            }
        }

        return lines;
    }
};
