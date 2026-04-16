class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();

        unordered_map<int, vector<int>> indices;

        for (int i = 0; i < n; i++) {
            indices[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {

            vector<int>& arr = indices[nums[q]];
            int m = arr.size();

            if (m == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(arr.begin(), arr.end(), q) - arr.begin();

            int next = arr[(pos + 1) % m];
            int prev = arr[(pos - 1 + m) % m];

            int dist1 = min(abs(q - next), n - abs(q - next));
            int dist2 = min(abs(q - prev), n - abs(q - prev));

            ans.push_back(min(dist1, dist2));
        }

        return ans;
    }
};