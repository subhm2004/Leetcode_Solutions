class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        // state[i] = bulb i ka current state (false = OFF, true = ON)
        vector<bool> state(101, false);

        // toggle operation
        for (int bulb : bulbs) {
        state[bulb] = (state[bulb]) ? 0 : 1;
        }

        // collect ON bulbs
        vector<int> ans;
        for (int i = 1; i <= 100; i++) {
            if (state[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};