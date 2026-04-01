class Solution { // same as leetcode astroid collison LC 735 
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dir) {
        int n = pos.size();

        vector<pair<int,int>> arr; // {position, index}
        for (int i = 0; i < n; i++) {
            arr.push_back({pos[i], i});
        }

        sort(arr.begin(), arr.end());

        stack<int> st; // store indices

        for (auto &p : arr) {
            int i = p.second;

            while (!st.empty() && dir[st.top()] == 'R' && dir[i] == 'L') {
                int j = st.top();

                if (health[j] < health[i]) {
                    st.pop();
                    health[j] = 0;
                    health[i]--; // current loses 1
                }
                else if (health[j] > health[i]) {
                    health[j]--; // stack loses 1
                    health[i] = 0;
                    break;
                }
                else { // dono ki health 0 ho gyi 
                    st.pop();
                    health[i] = 0;
                    health[j] = 0;

                    break;
                }
            }

            if (health[i] > 0) {
                st.push(i);
            }
        }

        // survivors in original order
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (health[i] > 0)
                ans.push_back(health[i]);
        }

        return ans;
    }
};