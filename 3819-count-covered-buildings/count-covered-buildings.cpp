class Solution {
public:
    bool left_wala_neighbor_hai(const set<int>& row_set, int y_coordinate) {
        auto it = row_set.lower_bound(y_coordinate);
        return it != row_set.begin() && *(prev(it)) < y_coordinate;
    }

    bool right_wala_neighbor_hai(const set<int>& row_set, int y_coordinate) {
        auto it = row_set.upper_bound(y_coordinate);
        return it != row_set.end();
    }

    bool upar_wala_neighbor_hai(const set<int>& col_set, int x_coordinate) {
        auto it = col_set.lower_bound(x_coordinate);
        return it != col_set.begin() && *(prev(it)) < x_coordinate;
    }

    bool neeche_wala_neighbor_hai(const set<int>& col_set, int x_coordinate) {
        auto it = col_set.upper_bound(x_coordinate);
        return it != col_set.end();
    }

    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> row_builg;
        unordered_map<int, set<int>> col_builg;

        for ( auto& building : buildings) {
            int x = building[0], y = building[1];
            row_builg[x].insert(y);
            col_builg[y].insert(x);
        }

        int ans = 0;

        for (const auto& building : buildings) {
            int x = building[0], y = building[1];
            auto& row_set = row_builg[x];
            auto& col_set = col_builg[y];

            bool left_Wala_Neighbor = left_wala_neighbor_hai(row_set, y);
            bool right_Wala_Neighbor = right_wala_neighbor_hai(row_set, y);
            bool upar_Wala_Neighbor = upar_wala_neighbor_hai(col_set, x);
            bool neeche_Wala_Neighbor = neeche_wala_neighbor_hai(col_set, x);

            if (left_Wala_Neighbor && right_Wala_Neighbor && upar_Wala_Neighbor && neeche_Wala_Neighbor) {
                ans++;
            }
        }

        return ans;
    }
};

