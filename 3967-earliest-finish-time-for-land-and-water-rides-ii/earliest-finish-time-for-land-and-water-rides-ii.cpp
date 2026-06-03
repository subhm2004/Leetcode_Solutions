class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
                           vector<int>& wd) {
        int result = INT_MAX;
        vector<pair<int, int>> pani;
        vector<pair<int, int>> dharti;

        for (int i = 0; i < ls.size(); i++) {
            dharti.push_back({ls[i] + ld[i], ls[i]});
        }
        for (int i = 0; i < ws.size(); i++) {
            pani.push_back({ws[i] + wd[i], ws[i]});
        }
        sort(pani.begin(), pani.end());
        sort(dharti.begin(), dharti.end());

        for (auto [pe, ps] : pani) {
             result = min(result, max(dharti[0].first, ps) + (pe - ps));
        }
        for (auto [de, ds] : dharti) {
             result = min(result, max(pani[0].first, ds) + (de - ds));
        }

        return result;
    }
};