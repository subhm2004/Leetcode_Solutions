struct Pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return ((long long)p.first << 2) ^ p.second;
    }
};
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
    
        unordered_set<pair<int,int>, Pair_hash> st;

        for (auto &p : points) {
            st.insert({p[0], p[1]});
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 != x2 && y1 != y2) {
                    if (st.count({x1, y2}) && st.count({x2, y1})) {
                        int area = abs(x2 - x1) * abs(y2 - y1);
                        ans = min(ans, area);
                    }
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
