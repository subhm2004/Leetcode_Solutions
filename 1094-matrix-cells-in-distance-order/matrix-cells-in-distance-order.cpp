class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>>cells;
        
        for(int r =0 ; r< rows ; r++){
            for(int c =0 ; c< cols ; c++){
                cells.push_back({r,c});
            }
        }
        
        sort(cells.begin(),cells.end(),[&](auto&a, auto&b){
            auto dist_a = abs(a[0]-rCenter) + abs(a[1]-cCenter);
            auto dist_b = abs(b[0]-rCenter) + abs(b[1]-cCenter);
            return dist_a < dist_b;
        });
        
        return cells;
    }
};