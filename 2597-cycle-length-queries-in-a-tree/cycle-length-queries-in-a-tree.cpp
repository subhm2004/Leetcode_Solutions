class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto& q : queries) {
            int a = q[0], b = q[1];
            int dist = 0;

            while (a != b) {
                if (a > b)
                    a /= 2;
                else
                    b /= 2;
                dist++;
            }

            ans.push_back(dist + 1); // +1 for the extra edge (jo hum add kr rhe hai)
        }

        return ans;
    }
};
