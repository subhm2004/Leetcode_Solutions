class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        int ans = INT_MAX;

        vector<int> prev;   // previous ending ORs

        for (int x : nums) {

            vector<int> cur;
            cur.push_back(x);

            for (int v : prev) {
                int val = v | x;
                if (cur.back() != val)
                    cur.push_back(val);
            }

            for (int v : cur) {
                ans = min(ans, abs(v - k));
            }

            prev = cur;
        }

        return ans;
    }
};
