class Solution {
public:
    vector<int> difference_array_technique(vector<vector<int>>& queries, int n) {
        vector<int> diff(n, 0);

        for (const auto& q : queries) {
            int l = q[0] ;
            int r = q[1] ;
            int val = q[2];

            diff[l] += val;
            if (r + 1 < n)
                diff[r + 1] -= val;
        }

        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> queries;
        for (auto& trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2] - 1;  // end - 1 because it's exclusive

            queries.push_back({start , end , passengers});   
        }

        vector<int> ans = difference_array_technique(queries, 1001);

        for (int p : ans) {
            if (p > capacity) return false;
        }

        return true;
    }
};
