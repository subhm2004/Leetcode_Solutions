class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans(m, 0);

        for (int i = 0; i < m; i++) {
            int r = startPos[0];
            int c = startPos[1];
            int steps = 0;

            // robot start karega instruction s[i] se
            for (int j = i; j < m; j++) {
                char move = s[j];

                if (move == 'L') c--;
                else if (move == 'R') c++;
                else if (move == 'U') r--;
                else if (move == 'D') r++;

                if (r < 0 || r >= n || c < 0 || c >= n) break;

                steps++;
            }

            ans[i] = steps;
        }
        return ans;
    }
};
