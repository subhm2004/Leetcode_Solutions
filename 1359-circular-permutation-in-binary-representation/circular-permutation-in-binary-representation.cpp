class Solution {
public:
    vector<int> gray_code(int n) {
        vector<int> ans;
        for (int i = 0; i < (1 << n); ++i) {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }

    vector<int> circularPermutation(int n, int start) {
        vector<int> g = gray_code(n);
        int idx = 0;
        for (int i = 0; i < g.size(); i++) {
            if (g[i] == start) {
                idx = i;
                break;
            }
        }
        vector<int> ans;
        for (int i = 0; i < g.size(); i++) {
            ans.push_back(g[(idx + i) % g.size()]);
        }
        return ans;
    }
};
