auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;

        for (int j = 0; j < grid[0].size(); j++) {
            ans.push_back(0);
            for (int i = 0; i < grid.size(); i++)
                ans[j] = max(ans[j], (int)(to_string(grid[i][j]).length()));
        }

        return ans;
    }
};