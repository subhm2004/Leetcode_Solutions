class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();

        // Har unique x ke liye uska sabse bada y store karne ke liye map
        unordered_map<int, int> maxYforEachX;

        // Dono arrays ko traverse karo aur har unique x ke liye max y save karo
        for (int i = 0; i < n; ++i) {
            int xi = x[i];
            int yi = y[i];

            // Agar x[i] pehle nahi aaya ya ab wala y[i] bada hai, toh update
            // karo
            if (maxYforEachX.find(xi) == maxYforEachX.end() ||
                maxYforEachX[xi] < yi) {
                maxYforEachX[xi] = yi;
            }
        }

        // Agar 3 se kam unique x values hai, toh valid triplet banana possible
        // nahi
        if (maxYforEachX.size() < 3) {
            return -1;
        }

        // Sabhi distinct x ke liye unke max y values ek vector me dalo
        vector<int> topY;
        for (const auto& pair : maxYforEachX) {
            topY.push_back(pair.second);
        }

        sort(topY.begin(), topY.end()); // chhoti se badi
        int m = topY.size();
        return topY[m - 3] + topY[m - 2] + topY[m - 1];
    }
};
